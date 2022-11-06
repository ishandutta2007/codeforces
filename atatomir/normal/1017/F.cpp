#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define tp unsigned int
const int maxSize = 300000000;
const ll conf = (1LL << 32) - 1;

ll n, A, B, C, D, i, j, act;
bitset<(maxSize / 3) + 11> data;
ll ans;

ll F(tp x) {
    ll ans = D;
    ll b = x;

    ans = (ans + x * C) & conf;

    x = (x * b) & conf;
    ans = (ans + x * B) & conf;

    x = (x * b) & conf;
    ans = (ans + x * A) & conf;

    return ans;
}

void add_prime(ll act) {
    ll aux = F(act);
    ll cnt = 0;
    ll b = act;

    while (act <= n) {
        cnt += n / act;
        act *= b;
    }

    ans += aux * cnt;
    ans &= conf;
}

void rm(ll x) {
    ll i, aux, xmod;

    i = x * x;
    xmod = x % 6;
    aux = i % 6;

    for (; i <= n; i += x) {

        if (aux == 1 || aux == 5) {
            if (aux == 1) {
                data[(i - 1) / 3] = true;
            } else {
                data[((i + 1) / 3) - 1] = true;
            }
        }

        aux = (aux + xmod);
        if (aux >= 6) aux -= 6;
    }
}

void run() {
    ll i, j;

    for (i = 1; 6 * i - 1 <= n; i++) {
        if (data[2 * i - 1] == 0) {
            add_prime(6 * i - 1);
            rm(6 * i - 1);
        }
        if (data[2 * i] == 0 && 2 * i + 1 <= n) {
            add_prime(6 * i + 1);
            rm(6 * i + 1);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);
    srand(time(NULL));


    cin >> n >> A >> B >> C >> D;
    if (n >= 2) add_prime(2);
    if (n >= 3) add_prime(3);

    run();
    cout << ans;



    return 0;
}