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

#define maxN 500011

struct Buffer {
    public:
        Buffer(int _dim) {
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        Buffer& operator>>(int &dest) {
            while (!is_digit(data[pos]))
                if (++pos == dim)
                    refill();

            dest = 0;
            while (is_digit(data[pos])) {
                dest = dest * 10 + data[pos] - '0';
                if (++pos == dim)
                    refill();
            }
            return *this;
        }

    private:
        int dim, pos;
        vector<char> data;

        bool is_digit(char c) {
            return '0' <= c && c <= '9';
        }

        void refill() {
            pos = 0;
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
        }
};

struct card {
    int a, b, c;
};

int n, i, l1, l2, l3;
card C[maxN];
int h[maxN];
ll sum[maxN];

int rest_a[maxN], rest_b[maxN];
int la, lb;
ll ans;

ll get_pos(ll val) {
    static ll bg = 1LL << 20;
    ll ans = 0;

    while (bg > l1) bg >>= 1;

    for (ll step = bg; step > 0; step >>= 1)
        if (ans + step <= l1)
            if (h[ans + step] > val)
                ans += step;

    return ans;
}

inline void mv(int& a, int b) {
    if (a > b) a = b;
}

int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin(1 << 20);

    fin >> n >> l1 >> l2 >> l3;
    for (i = 1; i <= n; i++)
        fin >> C[i].a >> C[i].b >> C[i].c;

    for (i = 1; i <= l1; i++) h[i] = l2;
    for (i = 1; i <= l3; i++) rest_a[i] = l1, rest_b[i] = l2;
    for (i = 1; i <= n; i++) {
        h[l1 - C[i].a + 1] = min(h[l1 - C[i].a + 1], l2 - (C[i].b + 1) + 1);

        mv(rest_a[l3 - C[i].c + 1], l1 - (C[i].a + 1) + 1);
        mv(rest_b[l3 - C[i].c + 1], l2 - (C[i].b + 1) + 1);
    }

    h[l1 + 1] = 0;
    for (i = 2; i <= l1; i++) h[i] = min(h[i], h[i - 1]);
    for (i = 1; i <= l1; i++) sum[i] = sum[i - 1] + h[i];

    la = l1;
    lb = l2;
    for (i = 1; i <= l3; i++) {
        //! se parcurge in ordine inversa a valorii
        la = min(la, rest_a[i]);
        lb = min(lb, rest_b[i]);

        ll p = get_pos(lb);
        p = min(p, 1LL * la);

        ans += 1LL * p * lb;
        ans += 1LL * sum[la] - sum[p];
    }

    cout << ans;

    return 0;
}