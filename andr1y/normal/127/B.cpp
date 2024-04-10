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
#define N 105
#define INF 101111111111111
using namespace std;
ll cnt[N];
int main(){
	FAST;
	ll n;
	cin >> n;
	for(ll i= 0, x =0;i<n;i++){
		cin >> x;
		cnt[x] ++;
	}
	ll cnc = 0;
	for(ll i =1;i<=100;i++){
		cnc += cnt[i]/2;
	}
	cout << cnc/2 << endl;
}