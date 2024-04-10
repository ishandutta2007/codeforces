#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1000011
#define mod 1000000007

const int dim = 1000000;
const int cnt_tp = 25;

class Buffer {
    public:
        Buffer(int _dim) {
            //freopen("test.in", "r", stdin);
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        Buffer& operator>>(int &dest) {
            while (!is_digit(data[pos]) && data[pos] != '-')
                if (++pos == dim)
                    refill();

            dest = 0;
            int sgn = 1;

            if (data[pos] == '-') {
                sgn = -1;
                if (++pos == dim)
                    refill();
            }

            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }

            dest *= sgn;

            return *this;
        }

    private:
        int dim, pos;
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

struct query {
    int r, n, id;

    bool operator<(const query& who)const {
        return r < who.r;
    }
};

int q, i, rr, ss, dd;
vector<query> Q;
query qaux;
ll dp[2][cnt_tp];

vector<int> dvs[maxN];
ll ans[maxN];

void pre() {
    ll i, j;

    for (i = 2; i <= dim; i++) {
        if (dvs[i].size()) {

            int cnt;
            int aux = i;

            for (auto& e : dvs[i]) {
                cnt = 0;

                while (aux % e == 0) {
                    cnt++;
                    aux /= e;
                }

                e = cnt;
            }

            continue;
        }

        dvs[i] = {1};
        for (j = 2 * i; j <= dim; j += i)
            dvs[j].pb(i);
    }
}

void get_next() {
    rr++;

    dp[dd][0] = dp[ss][0];
    for (int i = 1; i <= 20; i++) {
        dp[dd][i] = dp[dd][i - 1] + dp[ss][i];
        dp[dd][i] %= mod;
    }

    swap(ss, dd);
}

int main()
{
    Buffer fin(1 << 20);

    fin >> q;
    for (i = 1; i <= q; i++) {
        fin >> qaux.r >> qaux.n;
        qaux.id = i;
        Q.pb(qaux);
    }


    sort(Q.begin(), Q.end());

    ss = 0; dd = 1;
    dp[ss][0] = 1;
    for (i = 1; i <= 20; i++) {
        dp[ss][i] = 2;
    }

    pre();


    rr = 0;
    for (auto e : Q) {
        while (rr < e.r)
            get_next();

        ans[e.id] = 1;
        for (auto pp : dvs[e.n])
            ans[e.id] = (ans[e.id] * dp[ss][pp]) % mod;
    }

    for (i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);



    return 0;
}