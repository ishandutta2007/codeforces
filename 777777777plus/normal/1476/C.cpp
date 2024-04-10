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
int n;
ll c[N];
ll a[N],b[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)c[i]=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)b[i]=read();
		if(n==1){
			puts("0");
			continue;
		}
		ll w=abs(a[2]-b[2])+1,ans=0;
		int last=1;
		for(int i=2;i<=n;++i){
			ans=max(ans,c[i]+w);
			w+=c[i]-abs(a[i+1]-b[i+1])+1;
			w=max(w,abs(a[i+1]-b[i+1])+1);
			if(a[i+1]==b[i+1])w=1,last=i;
		}
		cout<<ans<<endl;
	}
}