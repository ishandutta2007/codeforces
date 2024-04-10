#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[200100],b[200100],c[200100];
vector<int>u,v,w;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),m=0;
		for(int i=1;i<=n;i++)c[i]=b[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!c[a[i]])c[b[i]=a[i]]=i,m++;
		}
		for(int i=1;i<=n;i++){
			if(!b[i]&&!c[i])u.push_back(i);
			else if(!b[i])v.push_back(i);
			else if(!c[i])w.push_back(i);
		}
		while(u.size()>=2){
			int x=u.back();u.pop_back();
			int y=u.back();u.pop_back();
			b[x]=y,b[y]=x;
			c[x]=y,c[y]=x;
		}
		while(!v.empty()&&!w.empty()){
			int x=v.back();v.pop_back();
			int y=w.back();w.pop_back();
			b[x]=y,c[y]=x; 
		}
		if(!u.empty()){
			int x=u.back();u.pop_back();
			b[c[a[x]]]=x,c[x]=c[a[x]];
			b[x]=a[x],c[a[x]]=x;
		}
		printf("%d\n",m);
		for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
	}
	return 0;
}