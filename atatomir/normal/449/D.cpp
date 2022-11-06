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

#define mod 1000000007

const int bts = 20;
const int limit = 1 << bts;

class Buffer {
    public:
        Buffer(int _dim) {
            dim = _dim;
            data.resize(dim + 11);
            refill();
        }

        Buffer& operator>>(int& a) {
            while (!is_digit(data[pos]))
                if (++pos == dim)
                    refill();

            a = 0;
            while (is_digit(data[pos])) {
                a = a * 10 + data[pos] - '0';
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
            memset(&data[0], 0, dim);
            fread(&data[0], 1, dim, stdin);
            pos = 0;
        }
};

int n, i, x;
ll data[limit];

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void supraset() {
    int i, j;

    for (i = 0; i < bts; i++)
        for (j = 0; j < limit; j++)
            if ( (j & (1 << i)) == 0 )
                add(data[j], data[j ^ (1 << i)]);
}

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void inv_supraset() {
        int i, j;

    for (i = 0; i < bts; i++)
        for (j = 0; j < limit; j++)
            if ( (j & (1 << i)) == 0 )
                add(data[j], mod - data[j ^ (1 << i)]);
}


int main()
{
    //freopen("test.in","r",stdin);
    Buffer fin(1 << 20);

    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> x, data[x]++;

    supraset();
    for (i = 0; i < limit; i++)
        data[i] = poww(2, data[i]);

    inv_supraset();
    cout << data[0];


    return 0;
}