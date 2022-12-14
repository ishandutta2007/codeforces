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


int main()
{
    srand (time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll L, v, l, r;
        cin >> L >> v >> l >> r ;
        ll p = r / v - (l - 1) / v;
//        cout << p << endL;

        ll o = L / v;
//        cout << o << endL;

        cout << o - p << endL;
    }



}