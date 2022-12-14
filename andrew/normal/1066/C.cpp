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

ll p[555555];

int main()
{
    srand (time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n;

    ll l = 1;
    ll r = -1;
    cin >> n;

    char c;
    ll a;


    cin >> c;
    cin >> a;

    p[a] = 0;

    l = 0;
    r = 0;
    for (int i = 2; i <= n; i++) {
        cin >> c;
        cin >> a;
        if (c == 'L') {
            l--;
            p[a] = l;
//            cout << "pos " << a << " == " << l << endl;
        } else

        if (c == 'R') {
            r++;
            p[a] = r;
//            cout << "pos " << a << " == " << r << endl;
        } else

        if (c == '?') {
//            cout << p[a] << "CCC " << a << endL;
            cout << abs(min(abs(l - p[a]), abs(r - p[a]))) << endL;
        }
//        cout << l << " " << r << endl;
    }

}