#include<cstdio>
#include<vector>
using namespace std;
int t,n,m,k,x,y,z,a[100039],b[100039],c[100039],ans[100039],h[100039],flag,now,he[100039];
vector<int> g[100039];
int main(){
	register int i;
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(i=1;i<=n;i++) g[i].clear(),h[i]=0,ans[i]=0,he[i]=0;now=0;flag=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=m;i++) scanf("%d",&c[i]);
		for(i=1;i<=n;i++) if(a[i]!=b[i]) g[b[i]].push_back(i),h[b[i]]++;
		for(i=1;i<=n;i++) if(a[i]==b[i]) he[a[i]]=i;
		for(i=m;i;i--){
			if(h[c[i]]) ans[i]=g[c[i]][--h[c[i]]],now=ans[i];
			else {
				if(!g[c[i]].size()){
					if(!now&&!he[c[i]]){flag=1;break;}
					else ans[i]=now?now:(he[c[i]],now=he[c[i]]);
				}
				else ans[i]=g[c[i]][0];
			}
		}
		for(i=1;i<=n;i++) if(h[i]) flag=1;
		if(flag) printf("NO\n");
		else {
			printf("YES\n");
			for(i=1;i<=m;i++) printf("%d ",ans[i]);printf("\n");
		} 
	}
}