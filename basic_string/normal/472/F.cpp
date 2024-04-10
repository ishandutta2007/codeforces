#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int x[N],y[N],a[33],b[33];
vector<pair<int,int>>u,v;
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",x+i);
		for(j=29;~j;--j)if(x[i]>>j&1){
			if(!a[j]){
				a[j]=i;
				break;
			}
			x[i]^=x[a[j]],u.push_back({i,a[j]});
		}
	}
	for(i=1;i<=n;++i){
		scanf("%d",y+i);
		for(j=29;~j;--j)if(y[i]>>j&1){
			if(!b[j]){
				b[j]=i;
				break;
			}
			y[i]^=y[b[j]],v.push_back({i,b[j]});
		}
	}
	for(i=29;~i;--i)if(b[i]){
		for(y[b[i]]^=x[a[i]],j=i-1;~j;--j)if(y[b[i]]>>j&1)y[b[i]]^=x[a[j]],u.push_back({a[i],a[j]});
		if(y[b[i]])puts("-1"),exit(0);
	}else if(a[i])u.push_back({a[i],a[i]}),a[i]=0;
	for(i=29;~i;--i)if(b[i]&&a[i]!=b[i]){
		u.push_back({a[i],b[i]}),u.push_back({b[i],a[i]}),u.push_back({a[i],b[i]});
		for(j=29;~j;--j)if(a[j]==b[i])a[j]=a[i];
	}
	cout<<u.size()+v.size()<<'\n';
	for(auto i:u)printf("%d %d\n",i.first,i.second);
	for(auto i=v.rbegin();i!=v.rend();++i)printf("%d %d\n",i->first,i->second);
	return 0;
}