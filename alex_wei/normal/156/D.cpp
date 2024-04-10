#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define gc getchar()

inline int read(){
	int x=0,sign=0; char s=gc;
	while(!isdigit(s))sign|=s=='-',s=gc;
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
	return sign?-x:x;
}

const int N=1e5+5;

ll n,m,k,p,f[N],sz[N],ans=1;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(sz[x]<sz[y])swap(x,y);
	sz[x]+=sz[y],f[y]=x;
}

int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(int i=1,x,y;i<=m;i++)merge(x=read(),y=read());
	for(int i=1;i<=n;i++)if(f[i]==i)ans=ans*sz[i]%p,k++;
	if(k==1)cout<<1%p<<endl;
	else{
		while((k--)-2)ans=ans*n%p;
		cout<<ans<<endl;
	}
	return 0;
}