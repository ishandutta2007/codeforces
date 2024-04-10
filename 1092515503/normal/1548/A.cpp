#include<bits/stdc++.h>
using namespace std;
int n,m,q,res;
set<int>s[200100];
#define calc(x) (s[x].empty()||*s[x].rbegin()<x)
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),s[x].insert(y),s[y].insert(x);
	for(int x=1;x<=n;x++)res+=calc(x);
	scanf("%d",&q);
	for(int i=1,tp,x,y;i<=q;i++){
		scanf("%d",&tp);
		if(tp==1){
			scanf("%d%d",&x,&y);
			res-=calc(x),res-=calc(y);
			s[x].insert(y),s[y].insert(x);
			res+=calc(x),res+=calc(y);
		}
		if(tp==2){
			scanf("%d%d",&x,&y);
			res-=calc(x),res-=calc(y);
			s[x].erase(y),s[y].erase(x);
			res+=calc(x),res+=calc(y);
		}
		if(tp==3)printf("%d\n",res);
	}
	return 0;
}