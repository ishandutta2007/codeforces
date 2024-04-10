#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
main(){
    FAST;
    ll t;
    cin >> t;
    while(t--){
    	ll b, p, f, h, c;
    	cin >> b >> p >> f >> h >> c;
    	ll create_p = min(p, b/2);
    	ll create_f = min(f, b/2);
    	cout << max(create_p*h+min(f, max(0ll, b/2-create_p))*c, create_f*c+min(p, max(0ll, b/2-create_f))*h) << endl;
    }
}