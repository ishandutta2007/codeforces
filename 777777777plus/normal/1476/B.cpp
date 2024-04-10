#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}

int T;
ll n,k,p[N];

int main(){
	T=read();
	while(T--){
		n=read();k=read();
		for(int i=1;i<=n;++i)p[i]=read();
		ll val=p[1],ans=0;
		for(int i=2;i<=n;++i){
			ll nex=(p[i]*100+k-1)/k;
			if(val<nex){
				ans+=nex-val;
				val=nex;
			}
			val+=p[i];
		}
		cout<<ans<<endl;
	}
}