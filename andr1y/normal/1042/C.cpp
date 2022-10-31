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
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 200200
#define INF 101111111111111LL
using namespace std;
using python = void;

ll a[N];
bool used[N];
ll n;
void out_smp(){
	ll allto = 1;
	while(used[allto]) allto++;
	for(ll i = allto+1;i<=n;i++){
		if(!used[i]) cout << "1 " << i << " " << allto << '\n';
	}
	exit(0);
}
signed main(){
	FAST;
	cin >> n;
	vector<ll> zeros;
	ll vc = 0, mfvv = -INF, mfvp = 0;
	for(ll i =1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 0) zeros.pb(i);
		if(a[i] < 0){
			vc++;
			if(a[i] > mfvv){
				mfvv = a[i];
				mfvp = i;
			}
		}
	}
	if(zeros.size() == 0){
		if(vc&1){
			used[mfvp] = 1;
			cout << "2 " << mfvp << '\n';
			out_smp();
		}else out_smp();
	}else{
		if(zeros.size() == n){
			out_smp();
		}else if(zeros.size() == n-1 && vc){
			if(a[n] < 0) swap(a[n], a[1]);
			out_smp();
		}


		ll allto = zeros[0];
		used[allto] = 1;
		for(auto i : zeros){
			if(i == allto) continue;
			used[i] = 1;
			cout << "1 " << i << " " << allto << '\n';
		}
		if(vc&1){
			used[mfvp] = 1;
			cout << "1 " << mfvp << " " << allto << '\n';
		}
		cout << "2 " << allto << '\n';
		out_smp();
	}
}