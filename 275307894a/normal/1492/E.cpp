#include<bits/stdc++.h>
#define R(n) rand()*rand()%(n)+1
using namespace std;
int n,m,k,x,y,z,flag[250039],fl,a[250039],c[250039],cnt,ans;
double s;
vector<int> f[250039],g[250039],fs[250039];
int main(){
//	freopen("1.in","r",stdin);
	srand(time(0));
	register int i,j,h;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		f[i].push_back(0);
		for(j=1;j<=m;j++) scanf("%d",&x),f[i].push_back(x);
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++) c[j]=f[j][i];
		sort(c+1,c+n+1);
		g[i].push_back(0);fs[i].push_back(0);
		for(j=1;j<=n;j=h){
			for(h=j;h<=n;h++) if(c[j]!=c[h]) break;
			cnt=h-j;while(cnt>0) g[i].push_back(c[j]),cnt-=R(6);fs[i].push_back(c[j]); 
		}
	}
	while(1){
		if(clock()>500) break;fl=ans=0;
		for(i=1;i<=m;i++){
			x=R(g[i].size()-1);
			if(ans){
				for(j=1;j<=g[i].size();j++) if(g[i][j]==f[ans][i]){x=j;break;}
			}
			for(j=1;j<=n;j++) 
			if(f[j][i]!=g[i][x]) {
				flag[j]++;
				if(flag[j]==2){
					ans=j;
				} 
				if(flag[j]>2){fl=1;break;}
			}
			a[i]=x;
			if(fl) break;
		}
		if(fl){
			for(i=1;i<=n;i++) flag[i]=0;
		}
		else{
			printf("Yes\n");
			for(i=1;i<=m;i++) printf("%d ",g[i][a[i]]);return 0;
		}
	}
	while(1){
		if(clock()>1450) break;fl=ans=0;
		for(i=1;i<=m;i++){
			x=R(fs[i].size()-1);
			if(ans){
				for(j=1;j<=fs[i].size();j++) if(fs[i][j]==f[ans][i]){x=j;break;}
			}
			for(j=1;j<=n;j++) 
			if(f[j][i]!=fs[i][x]) {
				flag[j]++;
				if(flag[j]==2){
					ans=j;
				} 
				if(flag[j]>2){fl=1;break;}
			}
			a[i]=x;
			if(fl) break;
		}
		if(fl){
			for(i=1;i<=n;i++) flag[i]=0;
		}
		else{
			printf("Yes\n");
			for(i=1;i<=m;i++) printf("%d ",fs[i][a[i]]);return 0;
		}
	}
	while(1){
		if(clock()>1950) break;fl=ans=0;
		for(i=m;i;i--){
			x=R(fs[i].size()-1);
			if(ans){
				for(j=1;j<=fs[i].size();j++) if(fs[i][j]==f[ans][i]){x=j;break;}
			}
			for(j=1;j<=n;j++) 
			if(f[j][i]!=fs[i][x]) {
				flag[j]++;
				if(flag[j]==2){
					ans=j;
				} 
				if(flag[j]>2){fl=1;break;}
			}
			a[i]=x;
			if(fl) break;
		}
		if(fl){
			for(i=1;i<=n;i++) flag[i]=0;
		}
		else{
			printf("Yes\n");
			for(i=1;i<=m;i++) printf("%d ",fs[i][a[i]]);return 0;
		}
	}
	printf("No\n");
}