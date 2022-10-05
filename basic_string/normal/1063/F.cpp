#include<bits/stdc++.h>
using namespace std;
const int N=524289;
using ul=unsigned long long;
ul h[N];
char s[N];
bool u[N],v[N];
namespace H{
	const int M=N-2;
	int he[N],ne[N],t;
	ul to[N];
	void add(ul x){
		int i=x&M,j;
		for(j=he[i];j;j=ne[j])if(to[j]==x)return;
		ne[++t]=he[i],to[t]=x,he[i]=t;
	}
	bool count(ul x){
		for(int j=he[x&M];j;j=ne[j])if(to[j]==x)return 1;
		return 0;
	}
	void clr(){memset(he,0,sizeof he),t=0;}
}
int main(){
	int n,i,w;
	bool f;
	scanf("%d%s",&n,s+1),memset(v,1,sizeof v);
	for(w=2;;++w){
		for(i=1;i<=n;++i)h[i]=h[i]*131+s[i+w-2];
		for(n-=w,i=n,f=0;i>0;--i){
			if(v[i+w])H::add(h[i+w]);
			if(H::count(h[i])||H::count(h[i+1]))u[i]=f=1;
		}
		if(!f)printf("%d",w-1),exit(0);
		memcpy(v,u,sizeof v),memset(u,0,sizeof u),H::clr();
	}
	return 0;
}