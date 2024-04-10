#include <iostream>
#include <algorithm>
#include <vector>

//19:42
using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        return *this;
    }
    inline InputReader &operator >>(char &n) {
        while(buffer[cursor] < 'a' || buffer[cursor] > 'z') {
            advance();
        }

        n = buffer[cursor];
        advance();
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};


const int NMAX = 500000 + 5;

int n;
vector <int> tree[NMAX];
int sz[NMAX];
int h[NMAX];
int mask[NMAX];

void dfsMask(int node) {
    sz[node] = 1;
    for (auto it: tree[node]) {
        h[it] = 1 + h[node];
        mask[it] ^= mask[node];
        dfsMask(it);
        sz[node] += sz[it];
    }
}

const int SIGMA = 22;
const int INF = 1 << 26;
int ans[NMAX];

int longest[1 << SIGMA];

int res;
void ask(int node) {
    res = max(res, h[node] + longest[mask[node]]);
    for (int i = 0; i < SIGMA; ++ i)
        res = max(res, h[node] + longest[mask[node] ^ (1 << i)]);
}

void dfsAsk(int node) {
    ask(node);
    for (auto it: tree[node])
        dfsAsk(it);
}

void dfsAdd(int node) {
    longest[mask[node]] = max(longest[mask[node]], h[node]);
    for (auto it: tree[node])
        dfsAdd(it);
}

void dfsRemove(int node) {
    longest[mask[node]] = -INF;
    for (auto it: tree[node])
        dfsRemove(it);
}

void dfs(int node, bool keep) {
    int maximum = -1, maxSon = -1;
    for (auto it: tree[node])
        if (sz[it] > maximum) {
            maximum = sz[it];
            maxSon = it;
        }

    //Solve small sons
    for (auto it: tree[node])
        if (it != maxSon) {
            dfs(it, false);
            ans[node] = max(ans[node], ans[it]);
        }

    //Solve large son
    if (maxSon != -1) {
        dfs(maxSon, true);
        ans[node] = max(ans[node], ans[maxSon]);
    }

    //Combine sons
    res = -INF;
    ask(node);
    longest[mask[node]] = max(longest[mask[node]], h[node]);
    for (auto it: tree[node])
        if (it != maxSon) {
            dfsAsk(it);
            dfsAdd(it);
        }
    ans[node] = max(ans[node], res - 2 * h[node]);

    //Discard
    if (!keep)
        dfsRemove(node);
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    cin >> n;
    for (int i = 2; i <= n; ++ i) {
        int father;
        char let;
        cin >> father >> let;

        tree[father].push_back(i);
        mask[i] = (1 << (let - 'a'));
    }

    dfsMask(1);
    for (int i = 0; i < (1 << SIGMA); ++ i)
        longest[i] = -INF;
    dfs(1, false);

    for (int i = 1; i <= n; ++ i)
        cout << ans[i] << " \n"[i == n];
    return 0;
}