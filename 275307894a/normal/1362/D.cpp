#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k,x,y,z,t[500039],fs[500039],flag;
struct yyy{int t,num;}s[500039];
inline bool cmp(yyy x,yyy y){return x.t<y.t;}
vector<int> f[500039];
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d%d",&x,&y),f[x].push_back(y),f[y].push_back(x);
	for(i=1;i<=n;i++) scanf("%d",&t[i]);
	for(i=1;i<=n;i++){
		for(j=0;j<f[i].size();j++)fs[t[f[i][j]]]++;
		flag=0;
		for(j=1;j<t[i];j++)if(!fs[j]){flag=1;break;}
		if(fs[t[i]]) flag=1;
		if(flag) break;
		for(j=0;j<f[i].size();j++)fs[t[f[i][j]]]--;
	}
	if(flag) printf("-1\n");
	else{
		for(i=1;i<=n;i++) s[i]=(yyy){t[i],i};
		sort(s+1,s+n+1,cmp);
		for(i=1;i<=n;i++) printf("%d ",s[i].num);
	}
}