#include <iostream>
#include <algorithm>
#include <vector>

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

class Gauss {
private:
    vector <int> base;

public:
    void add(int nr) {
        base.push_back(nr);
    }

    void computeBase() {
        int cnt = 0;
        for (int bit = 29; bit >= 0; -- bit) {
            bool found = false;
            for (int i = cnt; i < base.size(); ++ i)
                if (base[i] & (1 << bit)) {
                    found = true;
                    swap(base[i], base[cnt]);
                }

            if (!found)
                continue;

            for (int i = cnt + 1; i < base.size(); ++ i)
                if (base[i] & (1 << bit))
                    base[i] ^= base[cnt];
            ++ cnt;
        }
        base.resize(cnt);
    }

    int query(int nr) {
        for (auto it: base)
            if ((nr ^ it) < nr)
                nr ^= it;
        return nr;
    }
};

const int NMAX = 100000 + 5;
vector <pair <int, int> > graph[NMAX];

vector <Gauss> gausses;

int val[NMAX];
int comp[NMAX];
int comps;

void dfs(int node) {
    comp[node] = comps;
    for (auto it: graph[node])
        if (!comp[it.first]) {
            val[it.first] = val[node] ^ it.second;
            dfs(it.first);
        }
        else
            gausses[comps - 1].add(val[node] ^ val[it.first] ^ it.second);
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    int n, m = 0, q = 1;
    cin >> n >> m; //>> q;

    for (int i = 1; i <= m; ++ i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    for (int i = 1; i <= n; ++ i)
        if (!comp[i]) {
            ++ comps;
            gausses.push_back(Gauss());
            dfs(i);
            gausses.back().computeBase();
        }

    while (q --) {
        int a = 1, b = n;
        //cin >> a >> b;

        if (comp[a] != comp[b])
            cout << "FAIL\n";
        else
            cout << gausses[comp[a] - 1].query(val[a] ^ val[b]) << '\n';
    }
    return 0;
}