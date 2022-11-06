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

#define maxN 100011

const int bucket = 400;

class Buffer {
    public:
        Buffer(string name, int _dim) {
            //if (name != "")
            //    freopen(name.c_str(), "r", stdin);
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

struct que {
    int l, r;
    int id;

    bool operator<(const que& who) const {
        return mp(l / bucket, r) < mp(who.l / bucket, who.r);
    }
};

ll n, k, i, q, l, r;
ll tp[maxN];
ll a[maxN], here[maxN], pre[maxN], nxt[maxN];
vector<que> Q;

ll cnt;
map<ll, ll> M;
ll act[maxN];
ll val;
ll sol[maxN];


int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin("", 1 << 20);

    fin >> n >> k;
    for (i = 1; i <= n; i++) fin >> tp[i];
    for (i = 1; i <= n; i++) {
        fin >> a[i];
        if (tp[i] == 2) a[i] = -a[i];
        a[i] += a[i - 1];
    }

    fin >> q;
    for (i = 1; i <= q; i++) {
        fin >> l >> r;
        Q.push_back({l - 1, r, i});
    }

    sort(Q.begin(), Q.end());

    for (i = 0; i <= n; i++)
        if (M[a[i]] == 0)
            M[a[i]] = ++cnt;

    for (i = 0; i <= n; i++) {
        here[i] = M[a[i]];
        pre[i] = M[a[i] - k];
        nxt[i] = M[a[i] + k];
    }

    l = 0; r = -1; val = 0;
    for (auto e : Q) {

        while (e.l < l) {
            l--;
            if (nxt[l] != 0)
                val += act[nxt[l]];
            act[here[l]]++;
        }

        while (r < e.r) {
            r++;
            if (pre[r] != 0)
                val += act[pre[r]];
            act[here[r]]++;
        }

        while (l < e.l) {
            act[here[l]]--;
            if (nxt[l] != 0)
                val -= act[nxt[l]];
            l++;
        }

        while (e.r < r) {
            act[here[r]]--;
            if (pre[r] != 0)
                val -= act[pre[r]];
            r--;
        }

        sol[e.id] = val;
    }

    for (i = 1; i <= q; i++)
        printf("%lld\n", sol[i]);





    return 0;
}