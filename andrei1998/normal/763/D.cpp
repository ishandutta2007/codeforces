#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

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

const int NMAX = 200000 + 5;

int N;
int sz[NMAX];
vector <int> graph[NMAX];

const int MOD1 = 1000000000 + 7;
const int MOD2 = 1000000000 + 9;
const int C1 = 63;
const int C2 = 67;

int powC1[2 * NMAX];
int powC2[2 * NMAX];

pair <int, int> hs[NMAX];

bool cmp(const int &a, const int &b) {
    return hs[a] < hs[b];
}

//Global answer
int ans;
int nodeAns;

//Current stats
int current;
map <pair <int, int>, int> Map;

inline void addToMap(int node) {
    Map[hs[node]] ++;
    if (Map[hs[node]] == 1)
        current ++;
}

inline void removeFromMap(int node) {
    Map[hs[node]] --;
    if (Map[hs[node]] == 0)
        current --;
}

void computeDp(int node, int father) {
    hs[node] = {0, 0};

    sort(graph[node].begin(), graph[node].end(), cmp);
    for (auto it: graph[node])
        if (it != father){
            hs[node].first = (1LL * powC1[2 * sz[it]] * hs[node].first + hs[it].first) % MOD1;
            hs[node].second = (1LL * powC2[2 * sz[it]] * hs[node].second + hs[it].second) % MOD2;
        }

    hs[node].first = (1LL * hs[node].first * C1 + 1) % MOD1;
    hs[node].second = (1LL * hs[node].second * C2 + 1) % MOD2;
}

void dfsInit(int node, int father) {
    //Solve sons
    sz[node] = 1;
    for (auto it: graph[node])
        if (it != father){
            dfsInit(it, node);
            sz[node] += sz[it];
        }

    //Find hash of node
    computeDp(node, father);

    addToMap(node);
}

void dfsMove(int node, int father) {
    //Update ans
    if (current > ans) {
        ans = current;
        nodeAns = node;
    }

    vector <pair <int, int> > hPref(graph[node].size() + 2);
    //vector <pair <int, int> > hSuf(graph[node].size() + 2);

    //Compute pref
    hPref[0] = {0, 0};
    for (int i = 0; i < graph[node].size(); ++ i) {
        hPref[i + 1].first = (1LL * powC1[2 * sz[graph[node][i]]] * hPref[i].first + hs[graph[node][i]].first) % MOD1;
        hPref[i + 1].second = (1LL * powC2[2 * sz[graph[node][i]]] * hPref[i].second + hs[graph[node][i]].second) % MOD2;
    }

    pair <int, int> hSuf = {0, 0};
    int szSuf = 0;

    for (int i = graph[node].size() - 1; i >= 0; -- i) {
        //Call only for non-father

        if (graph[node][i] != father) {
            int oldSzNode = sz[node];
            int oldSzIt = sz[graph[node][i]];
            sz[node] -= sz[graph[node][i]];
            sz[graph[node][i]] = oldSzNode;

            pair <int, int> oldHsIt = hs[graph[node][i]];
            pair <int, int> oldHsNode = hs[node];

            removeFromMap(node);
            removeFromMap(graph[node][i]);

            //Go down
            hs[node].first = (1LL * hPref[i].first * powC1[szSuf] + hSuf.first) % MOD1;
            hs[node].second = (1LL * hPref[i].second * powC2[szSuf] + hSuf.second) % MOD2;
            hs[node].first = (1LL * hs[node].first * C1 + 1) % MOD1;
            hs[node].second = (1LL * hs[node].second * C2 + 1) % MOD2;

            computeDp(graph[node][i], 0);

            addToMap(node);
            addToMap(graph[node][i]);

            dfsMove(graph[node][i], node);

            removeFromMap(node);
            removeFromMap(graph[node][i]);

            //Raise back up
            hs[node] = oldHsNode;
            hs[graph[node][i]] = oldHsIt;

            addToMap(node);
            addToMap(graph[node][i]);

            sz[node] = oldSzNode;
            sz[graph[node][i]] = oldSzIt;
        }

        hSuf.first = (1LL * powC1[szSuf] * hSuf.first + hs[graph[node][i]].first) % MOD1;
        hSuf.second = (1LL * powC2[szSuf] * hSuf.second + hs[graph[node][i]].second) % MOD2;
        szSuf += 2 * sz[graph[node][i]];
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    InputReader cin;

    cin >> N;

    powC1[0] = powC2[0] = 1;
    for (int i = 1; i <= 2 * N; ++ i) {
        powC1[i] = (1LL * C1 * powC1[i - 1]) % MOD1;
        powC2[i] = (1LL * C2 * powC2[i - 1]) % MOD2;
    }

    for (int i = 1; i < N; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfsInit(1, 0);

    ans = current;
    nodeAns = 1;

    dfsMove(1, 0);

    cout << nodeAns << '\n';
    return 0;
}