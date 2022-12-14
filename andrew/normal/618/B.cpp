#include<bits/stdc++.h>
//#define ll int
#define ll long long
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define yn idehfushefuwheuf
#define y1 issdehfushefuwheuf
#define endL "\n"
#define all(a) a.begin(),a.end()
#define p_b push_back
#define pll pair<ll,ll>
#define vout(a); {cout<<a;return 0;}
#define sqr(a) ((a)*(a))


const ll gig = 1e18;
const ll gg = 25*1e6;
const ll mod = 1e9 + 7;

using namespace std;


ll n, m;
ll a[55][55];
ll p[55];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("1.out", "r", stdin);
//    freopen("1.out", "w", stdout);

    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int k = 1; k <  n; k++)
    for (int i = 1; i <= n; i++) {

        ll f = 1;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (a[i][j] == k) continue;
            if (a[i][j] != k && p[j] == a[i][j]) continue;
            f = 0;
        }
        if (f) {
            p[i] = k;
            break;
        }

    }

    for (int i = 1; i <= n; i++)
        if (p[i] != 0) cout << p[i] << " "; else cout << n << " ";


}