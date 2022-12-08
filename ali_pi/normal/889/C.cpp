#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=1E6+77;
const int mod=1E9+7;

LL P[maxn], D[maxn], S[maxn];
LL N, K, ans;

LL Pow(LL v, int p){
	LL ret=1;
	while(p){
		if(p&1) ret=(ret*v)%mod;
		v=(v*v)%mod;
		p>>=1;
	}
	return ret;
}

LL Div(LL a, LL b){
	return (a*Pow(b, mod-2))%mod;
}

int main(){
	P[0]=1;
	for(int i=1;i<maxn;++i) P[i]=(P[i-1]*i)%mod;
	cin>>N>>K;++K;
	for(int i=K+1;i<=N;++i){
		D[i]=(i-K)+S[i-1]-S[i-K];
		if(D[i]<0) D[i]+=mod;
		if(D[i]>=mod) D[i]-=mod;
		if(D[i]>=mod) D[i]-=mod;
		S[i]=S[i-1]+Div(D[i], i-1);
		if(S[i]>=mod) S[i]-=mod;
		D[i]=(D[i]*P[i-2])%mod;
	}
	for(int i=K+1;i<=N;++i){
		ans+=(D[i]*Div(P[N-1], P[i-1]))%mod;
		if(ans>=mod) ans-=mod;
	}
	cout<<ans<<endl;
}