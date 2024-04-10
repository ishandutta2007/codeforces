#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,q,ans;
set<int> s[200005];
int f(int x){
	if(s[x].empty()) return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) s[y].insert(x);
		else s[x].insert(y);
	}
	for(int i=1;i<=n;++i)ans+=f(i);
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		int t;
		scanf("%d",&t);
		if(t==3){
			printf("%d\n",ans);
			continue;
		}
		int x,y;
		scanf("%d%d",&x,&y);
		ans-=f(x);
		ans-=f(y);
		if(x>y)swap(x,y);
		if(t==2)s[x].erase(y);
		else s[x].insert(y);
		ans+=f(x);
		ans+=f(y);
	}
			
    return 0;
}