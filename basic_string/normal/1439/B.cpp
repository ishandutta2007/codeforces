#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int d[N],a[N];
bool b[N];
set<pair<int,int>>st;
unordered_set<int>s[N];
int main(){
	int T,n,m,o,i,j,k,l;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&o),st.clear();
		for(i=1;i<=n;++i)d[i]=0,s[i].clear(),s[i].insert(i),b[i]=0;
		for(i=1;i<=m;++i){
			scanf("%d%d",&j,&k);
			++d[j],++d[k];
			s[j].insert(k),s[k].insert(j);
		}
		for(i=1;i<=n;++i)st.insert({d[i],i});
		while(!st.empty()){
			i=(*st.begin()).second;
			if(d[i]>=o){
				printf("%d %d\n",1,(int)st.size());
				for(auto w:st)printf("%d ",w.second);
				putchar(10);goto gg;
			}
			if(d[i]==o-1){
				k=0;
				for(auto w:s[i])if(!b[w])a[++k]=w;
				for(j=1;j<=k;++j)for(l=1;l<=k;++l)if(!s[a[j]].count(a[l]))goto gg2;
				printf("%d\n",2);
				for(j=1;j<=k;++j)printf("%d ",a[j]);
				putchar(10);goto gg; 
				gg2:;
			}
			b[i]=1,st.erase(st.begin());
			for(auto w:s[i])if(!b[w]){
				st.erase({d[w],w}),--d[w],st.insert({d[w],w});
			}
		}
		puts("-1");
		gg:;
	}
	return 0;
}