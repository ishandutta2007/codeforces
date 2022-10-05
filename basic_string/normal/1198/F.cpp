#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
mt19937 rd(2);
unordered_map<int,int>mp;
int a[N],b[N],c[N],ans[N];
int main(){
	int n,m=0,i,d1,d2,x;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),++mp[a[i]];
	for(auto i:mp)for(x=min(i.second,2);x;--x)b[++m]=i.first;
	while(clock()<CLOCKS_PER_SEC*0.4){
		shuffle(b+1,b+m+1,rd),d1=d2=0;
		for(i=1;i<=m;++i){
			x=__gcd(d1,b[i]);
			if(x!=d1)d1=x,c[i]=1;
			else d2=__gcd(d2,b[i]),c[i]=2;
		}
		if(d1==1&&d2==1){
			puts("YES"),mp={};
			for(i=1;i<=m;++i)mp[b[i]]=c[i];
			for(i=1;i<=n;++i)printf("%d ",mp[a[i]]),mp[a[i]]=3-mp[a[i]];
			return 0;
		}
	}
	puts("NO");
	return 0;
}