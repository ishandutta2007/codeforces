#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
int b[N];
vector<int>v[N];
int main(){
	int T,n,i,j,k,l;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),memset(b,9,n+1<<2);
		for(i=1;i<=n;++i)v[i].clear();
		for(i=1;i<=n;++i){
			scanf("%d",&j);
			v[j].push_back(i);
		}
		for(i=1;i<=n;++i){
			l=0,k=0;
			for(auto j:v[i]){
				k=max(k,j-l),l=j;
			}
			k=max(k,n+1-l),b[k]=min(b[k],i);
		}
		for(i=1;i<=n;++i){
			b[i]=min(b[i],b[i-1]);
			if(b[i]>n)printf("-1 ");
			else printf("%d ",b[i]);
		}
		putchar(10);
	}
	return 0;
}//