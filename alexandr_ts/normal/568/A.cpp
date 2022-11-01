#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

bool used[MAX];
ll pows[N];
vector <ll> pal, pr;

ll cntDig(ll n) {
    return (ll)log10(n) + 1;
}

ll revNum(ll n) {
    ll ans = 0;
    ll n1 = n;
    fr(i, cntDig(n1)) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    pows[0] = 1;
    fr(i, 10)
        pows[i + 1] = pows[i] * 10;
    frab(i, 2, MAX)
        if (!used[i])
            for (ll j = i * i; j < MAX; j += i)
                used[j] = true;
    used[0] = used[1] = true;
    fr(i, MAX)
        if (!used[i])
            pr.pb(i);


    frab(i, 1, MAX2) {
        pal.pb(i * pows[cntDig(i)] + revNum(i));
        pal.pb((i / 10) * pows[cntDig(i)] + revNum(i));
    }

    sort(pal.begin(), pal.end());

    //fr(i, 100)
        //cout << pal[i] << endl;

    ll l = pr.size() - 1, r = pal.size() - 1;
    ll p, q;

    cin >> p >> q;
    for (ll i = MAX; i >= 0; i--) {
        while (r && pal[r] > i)
            r--;
        while (l && pr[l] > i)
            l--;
        //cout << r << " " << l << endl;
        if (l * q + q <= p + r * p) {
            cout << i;
            return 0;
        }
    }
    cout << 1;




}