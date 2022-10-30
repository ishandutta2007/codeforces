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
ll test(ll a, ll b, ll c){
	if(a>b) swap(a, b);
	ll na = min(b, a+c);
    ll nc = max(0ll, c-na+a);
    na += nc>>1;
    b += (nc>>1);
    return min(na, b);
}
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
    	ll a, b, c;
    	cin >> a >> b >> c;
    	cout << max(test(a, b, c), max(test(b, c, a), test(a, c, b))) << endl;
    }
}