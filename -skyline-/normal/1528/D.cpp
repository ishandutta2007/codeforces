#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,m,f[605][605];
ll d[605];
bool b[605];
void u(int x,ll y){if(y<d[x])d[x]=y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		f[x][y]=z;
	}
	d[n]=orz*1ll*n+1;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)d[j]=orz*1ll*n,b[j]=0;
		for(int j=0;j<n;++j)if(f[i][j])u(j,f[i][j]);
		for(int j=0;j<n;++j){
			int k=n;
			for(int t=0;t<n;++t)if(!b[t]&&d[t]<d[k])k=t;
			b[k]=1;
			u((k+1)%n,d[k]+1);
			for(int t=0;t<n;++t)if(f[k][t])u((t+d[k])%n,d[k]+f[k][t]);
		}
		d[i]=0;
		for(int j=0;j<n-1;++j)printf("%I64d ",d[j]);
		printf("%I64d\n",d[n-1]);
	}
    return 0;
}