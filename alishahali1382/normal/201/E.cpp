#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=1000000000000000100LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;

ll C(ll n, ll r){
	unsigned long long res=1;
	r=min(r, n-r);
	for (int i=1; i<=r; i++){
		if (res>=1e17) break ;
		res=res*(n+1-i)/i;
	}
	return res;
}

ll check(ll m, ll k){
	ll res=1, shit=k*m;
	for (int i=1; i<=k && shit; i++){
		ll cnt=C(k, i);
		//debug2(i, cnt)
		//debug(shit)
		if (shit/i>=cnt){
			shit-=cnt*i;
			res+=cnt;
		}
		else{
			res+=shit/i;
			shit=0;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//debug(check(7, 11))
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m;
		int dwn=-1, up=n;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (check(m, mid)>=n) up=mid;
			else dwn=mid;
		}
		cout<<up<<'\n';
	}
	
	
	return 0;
}
/*
1
1000000000 2345
*/