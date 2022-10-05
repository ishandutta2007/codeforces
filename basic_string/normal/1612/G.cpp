#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=1e6+9,O=1e6+5,iv=P+1>>1;
int S[N*2],*s=S+N,jc[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int m,i,ans=0,way=1;
	long long sum=0;
	for(cin>>m;m--;){
		cin>>i;
		++s[1-i],--s[1+i];
	}
	jc[0]=1;
	for(i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%P;
	for(i=-O;i<O;++i)s[i]+=s[i-2];
	for(i=-O;i<O;++i){
		way=way*1ll*jc[s[i]]%P;
		ans=(ans+(sum+1+sum+s[i])%P*s[i]%P*iv%P*i)%P;
		sum+=s[i];
	}cout<<(ans+P)%P<<' '<<way;
	return 0;
}