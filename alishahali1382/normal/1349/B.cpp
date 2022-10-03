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
const int MAXN=100110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int ps1[MAXN], ps2[MAXN];
int fen[MAXN*2];

void upd(int pos, int val){
	for (pos+=n+2; pos<MAXN; pos+=pos&-pos) fen[pos]=min(fen[pos], val);
}
int get(int pos){
	int res=inf;
	for (pos+=n+2; pos; pos-=pos&-pos) res=min(res, fen[pos]);
	return res;
}

int Solve(){
	cin>>n>>k;
	fill(fen, fen+2*n+20, inf);
	ans=0;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]==k) ans++;
		A[i]=(A[i]>=k);
	}
	if (!ans) kill("no")
	if (n==1) kill("yes")
	/*
	for (int i=1; i<=n; i++){
		if (i>1 && A[i]==k && A[i-1]>k) kill("yes")
		if (i<n && A[i]==k && A[i+1]>k) kill("yes")
	}*/
	/*
	for (int i=1; i<=n; i++){
		ps1[i]=ps1[i-1]+(A[i]>k)-(A[i]<=k);
		ps2[i]=ps2[i-1]+(A[i]<k)-(A[i]>=k);
	}
	for (int i=n; ~i; i--){
		//debug(i)
		if (get(ps1[i]-1)<ps2[i]) kill("yes")
		if (i<n) upd(ps1[i+1], ps2[i+1]);
	}
	*/
	for (int i=1; i<n; i++) if (A[i] && A[i+1]) kill("yes")
	for (int i=1; i+1<n; i++) if (A[i] && A[i+2]) kill("yes")
	kill("no")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
4 3
3 1 2 3


*/