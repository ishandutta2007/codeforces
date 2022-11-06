#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 400011

const int maxLog = 20;

class Buffer {
    public:
        Buffer(string name, int _dim) {
            if (name != "")
                freopen(name.c_str(), "r", stdin);
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        template<typename T>
        Buffer& operator>>(T &dest) {
            T sign = +1;
            dest = 0;

            while (!is_digit(data[pos]) && data[pos] != '-')
                if (++pos == dim)
                    refill();

            if (data[pos] == '-') {
                sign = -1;
                if (++pos == dim)
                    refill();
            }

            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }

            dest *= sign;
            return *this;
        }


    private:
        int pos, dim;
        vector<char> data;

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        void refill() {
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
            pos = 0;
        }
};

int q, n, i, last = 0;
ll tp, R, X;
ll W[maxN];
int lvl[maxN];
ll sum[maxN];
int dad[maxLog][maxN];

void add_node() {
    static int i, daddy;

    n++;
    W[n] = X;

    if (W[R] >= W[n]) {
        dad[0][n] = R;
    } else {
        daddy = R;
        for (i = maxLog - 1; i >= 0; i--) {
            if (dad[i][daddy] != 0)
                if (W[dad[i][daddy]] < W[n])
                    daddy = dad[i][daddy];
        }

        dad[0][n] = dad[0][daddy];
    }

    sum[n] = W[n] + sum[dad[0][n]];
    lvl[n] = lvl[dad[0][n]] + 1;

    for (i = 1; i < maxLog; i++)
        dad[i][n] = dad[i - 1][dad[i - 1][n]];
}

ll query() {
    static int node, i;

    if (W[R] > X) return 0;
    node = R;

    for (i = maxLog - 1; i >= 0; i--) {
        if (dad[i][node] == 0) continue;
        if (sum[R] - sum[dad[i][node]] + W[dad[i][node]] <= X)
            node = dad[i][node];
    }

    return lvl[R] - lvl[node] + 1;
}

int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin("", 1 << 20);

    lvl[1] = 1;
    sum[1] = 0;
    n = 1;

    fin >> q;
    for (i = 1; i <= q; i++) {
        fin >> tp >> R >> X;
        R ^= last;
        X ^= last;

        if (tp == 1) {
            add_node();
        } else {
            ll ans = query();
            printf("%lld\n", ans);
            last = ans;
        }
    }




    return 0;
}