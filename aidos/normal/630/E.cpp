#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >
#define y1 stdfdfdfdfsdfsdf
#define y2 stdfdfdfdfsdfsdfasd
#define x1 stdfdfdfdfsdfsdfadfasdfasdf
#define x2 stdfdfdfdfsdfsdfasdasdfasdfasdfasdf

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    ll ans = 0;
    ll x1, x2, y1, y2;
    cin >>x1 >> y1 >> x2 >> y2;
    ll cnt1, cnt2;
    //(abs(x1) % 2 == abs(x2) % 2){
    	cnt1 = (x2 - x1 + 2)/2;
    	cnt2 = cnt1 - 1;
    

   	//if(abs(y1) % 2 != abs(x1) % 2) swap(cnt1, cnt2);
    ll len1 = (y2 - y1 + 2)/2;
    ll len2 = y2 - y1 + 1;
    len2 -= len1;
    len1 *= cnt1;
    len2 *= cnt2;
    ans += len1;
    ans += len2;
    cout <<  ans  << endl;
    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}