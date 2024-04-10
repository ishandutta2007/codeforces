#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
using namespace std;

const int MAXN=1000010, mod=1000000007;

int n, m, k, u, v, x, y, a, b, ans;
int A[2][MAXN], dp[2][MAXN];
int lcp0[MAXN], lcp1[MAXN], lcp2[MAXN], sz;
string s, t, S[2];

void Build(){
	sz=max(s.size(), t.size());
	s.resize(sz+1, '#');
	t.resize(sz+1, '#');
	lcp0[sz]=lcp1[sz]=lcp2[sz]=0;
	for (int i=sz-1; ~i; i--){
		if (s[i]==t[i]) lcp0[i]=lcp0[i+1]+1;
		else lcp0[i]=0;
	}
	lcp1[sz-1]=0;
	for (int i=sz-2; ~i; i--){
		if (s[i]==t[i+1]) lcp1[i]=lcp1[i+1]+1;
		else lcp1[i]=0;
	}
	for (int i=sz-1; i; i--){
		if (s[i]==t[i-1]) lcp2[i]=lcp2[i+1]+1;
		else lcp2[i]=0;
	}
}
bool cmp(int x, int y){
	if (x==-1 && y==-1) return (lcp0[0]<sz && s[lcp0[0]]<t[lcp0[0]]);
	if (x==-1){
		if (lcp0[0]<y) return s[lcp0[0]]<t[lcp0[0]];
		return s[lcp1[y]+y]<t[lcp1[y]+y+1];
	}
	if (y==-1){
		if (lcp0[0]<x) return s[lcp0[0]]<t[lcp0[0]];
		return s[lcp2[x+1]+x+1]<t[lcp2[x+1]+x];
	}
	// x!=-1  y!=-1
	int mn=min(x, y), mx=max(x, y);
	if (lcp0[0]<mn) return s[lcp0[0]]<t[lcp0[0]];
	if (x<=y && lcp2[x+1]<y-x) return s[lcp2[x+1]+x+1]<t[lcp2[x+1]+x];
	if (x>y && lcp1[y]<x-y) return s[lcp1[y]+y]<t[lcp1[y]+y+1];
	return s[lcp0[mx+1]+mx+1]<t[lcp0[mx+1]+mx+1];
}

int main(){
	cin>>n;
	A[0][0]=-1;
	dp[0][0]=1;
	for (int shit=1; shit<=n; shit++){
		int x=(shit&1);
		cin>>S[x];
		s=t=S[x];
		Build();
		for (int i=0; i<=sz; i++) A[x][i]=i-1;
		sort(A[x], A[x]+sz+1, cmp);
		
		s=S[x];
		t=S[x^1];
		Build();
		int sum=0, j=0;
		for (int i=0; i<=sz; i++){
			while (j<=S[x^1].size() && !cmp(A[x][i], A[x^1][j]))
				sum=(sum+dp[x^1][j++])%mod;
			dp[x][i]=sum;
		}
	}
	for (int i=0; i<=S[n&1].size(); i++) ans=(ans + dp[n&1][i])%mod;
	cout<<ans<<"\n";
	
	return 0;
}