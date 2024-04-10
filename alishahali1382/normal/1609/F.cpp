#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define SZ(x) ((int)x.size())
#define Pop(x) __builtin_popcountll(x)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1000010, LOG=61;

int n, m, k, u, v, x, y, t, a, b, s1, s2;
ll A[MAXN], ans;
ll Mn1[MAXN], Mx1[MAXN];
ll Mn2[MAXN], Mx2[MAXN];
int ted1[LOG], ted2[LOG];

ll Solve(){
	ll res=0;
	// Mx1>=Mx2
	memset(ted1, 0, sizeof(ted1));
	memset(ted2, 0, sizeof(ted2));
	int j=1, jj=1;
	for (int i=1; i<=s1; i++){
		while (j<=s2 && Mx1[i]>=Mx2[j]) ted1[Pop(Mn2[j++])]++;
		while (jj<j && Mn1[i]<=Mn2[jj]) ted2[Pop(Mn2[jj++])]++;
//		debug2(j, jj)
		int p=Pop(Mx1[i]);
		if (Pop(Mn1[i])==p) res+=jj-1;
		res+=ted1[p]-ted2[p];
	}
//	debug(res)
//	debug2(Mn1[1], Mx1[1])
//	debug2(Mn2[1], Mx2[1])
//	debug2(s1, s2)
	
	// Mx1<Mx2
	memset(ted1, 0, sizeof(ted1));
	memset(ted2, 0, sizeof(ted2));
	j=1, jj=1;
	for (int i=1; i<=s2; i++){
		while (j<=s1 && Mx2[i]>Mx1[j]) ted1[Pop(Mn1[j++])]++;
		while (jj<j && Mn2[i]<=Mn1[jj]) ted2[Pop(Mn1[jj++])]++;
		int p=Pop(Mx2[i]);
		if (Pop(Mn2[i])==p) res+=jj-1;
		res+=ted1[p]-ted2[p];
	}
	return res;
}
void divide(int tl, int tr){
	if (tr-tl<=1){
		ans++;
		return ;
	}
	int mid=(tl+tr)>>1;
	divide(tl, mid);
	divide(mid, tr);
	s1=s2=1;
	Mn1[s1]=Mx1[s1]=A[mid-1];
	for (int i=mid-2; i>=tl; i--){
		s1++;
		Mn1[s1]=min(Mn1[s1-1], A[i]);
		Mx1[s1]=max(Mx1[s1-1], A[i]);
	}
	Mn2[s2]=Mx2[s2]=A[mid];
	for (int i=mid+1; i<tr; i++){
		s2++;
		Mn2[s2]=min(Mn2[s2-1], A[i]);
		Mx2[s2]=max(Mx2[s2-1], A[i]);
	}
	ans+=Solve();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	divide(1, n+1);
	cout<<ans<<"\n";
	
	return 0;
}
/*
2
1 3

*/