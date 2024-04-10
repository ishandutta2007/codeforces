#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <string>

using namespace std;

class InputReader {
    public:
        InputReader() {
            cursor = 0;
            fread(buffer, SIZE, 1, stdin);
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
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, stdin);
            }
        }
};

const int NMAX = 1005;
const int MMAX = 200005;
const int QMAX = 200005;

int n, m, q;
pair <int, int> edges[MMAX];

struct Query {
    int l, r, s, t;
    int pos;
} queries[QMAX];

bool operator<(const Query &a, const Query &b) {
    return a.l < b.l;
}

bool ans[QMAX];
int reach[NMAX][NMAX];

void add_edge(int a, int b, int c) {
    for (int i = 1; i <= n; ++ i)
        if (reach[b][i] < reach[a][i])
            reach[a][i] = reach[b][i];
    reach[a][b] = c;
}

int main()
{
    InputReader cin;

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (i != j)
                reach[i][j] = m + 1;

    for (int i = 1; i <= m; ++ i)
        cin >> edges[i].first >> edges[i].second;

    for (int i = 1; i <= q; ++ i) {
        cin >> queries[i].l >> queries[i].r >> queries[i].s >> queries[i].t;
        queries[i].pos = i;
    }

    sort(queries + 1, queries + q + 1);

    int pos = m;
    for (int i = q; i; -- i) {
        while (queries[i].l <= pos) {
            add_edge(edges[pos].first, edges[pos].second, pos);
            add_edge(edges[pos].second, edges[pos].first, pos);

            pos --;
        }

        ans[queries[i].pos] = (reach[queries[i].s][queries[i].t] <= queries[i].r);
    }

    string output;
    for (int i = 1; i <= q; ++ i)
        if (ans[i])
            output += "Yes\n";
        else
            output += "No\n";
    cout << output;
    return 0;
}