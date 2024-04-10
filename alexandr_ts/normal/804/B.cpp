#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 2e5 + 10;
const int M = 1e3 + 10;

ll ans[N];
ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> s;

    ll answ = 0;
    ll cntb = 0;
    //ll cnta = 0;

    for (int i = (int)s.size() - 1; i >= 0; i--)
        if (s[i] == 'a') {
            //cnta++;
            answ = (answ + cntb) % MOD;
            cntb *= 2;
            cntb %= MOD;
        }
        else {
            cntb++;
            cntb %= MOD;
        }


    cout << answ;
}