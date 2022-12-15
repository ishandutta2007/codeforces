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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

ll q, u, v, x, y, t, a, b, l, r;
ll A[MAXN];

ll Get(ll r){
	ll res=A[a*b]*(r/(a*b));
	r%=a*b;
	res+=A[r];
	return res;
}

ll shit(ll r){
	ll res=0;
	for (ll i=0; i<r; i++) res+=(i%a%b!=i%b%a);
	return res;
}

int Solve(){
	cin>>a>>b>>q;
	
	for (int i=0; i<a*b; i++) A[i+1]=A[i] + ((i%a%b)!=(i%b%a));
	while (q--){
		cin>>l>>r;
		cout<<Get(r+1)-Get(l)<<' ';
	}
	cout<<'\n';
	
	//debug2(shit(50))

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) Solve();
	
	return 0;
}
/*
1
7 10 1
100 200

*/