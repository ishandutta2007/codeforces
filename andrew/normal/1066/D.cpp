#include<bits/stdc++.h>

//#define ll int
#define  ll long long
//#define ll unsigned long long
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define yn idehfushefuwheuf
#define y1 issdehfushefuwheuf
#define endL "\n"
#define all(a) a.begin(),a.end()
#define p_b push_back
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define vll vector<ll>

const ll gig = 1e18;
const ll gg = 25*1e6;
const ll md = 1e9 + 7;
const ll N = 100050;
const double PI = 3.1415926535897932384626433832795;

using namespace std;

ll a[555555];

int main()
{
    srand (time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n, m, k, o = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];


    for (int i = n; i >= 1; i--) {
        o += a[i];
//        cout << i << " " << o << " " << m << endl;
        if (o >= k) {
//            cout << "!" << endl;
            m--;
            if (o != k) o = a[i]; else
            o = 0;
            if (m == 0) {
                if (o != 0) cout << n - i; else
                cout << n - i + 1;
                return 0;
            }
        }
    }

    cout << n;

}