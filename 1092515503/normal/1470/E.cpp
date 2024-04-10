#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 ii;
ll inf=1e18+10;
int T,n,K,q,p[500100];
ll f[500100][5];
ii s[500100][5];
template<typename T>void read(T&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
void print(int x){if(x>=10)print(x/10);putchar('0'+x%10);}
template<typename T>void ADD(T&x,ll y){if((x+=y)>=inf)x=inf;}
void mina(){
    read(n),read(K),read(q);
	for(int i=1;i<=n;i++)read(p[i]);for(int i=1;i<=K;i++)p[n+i]=n+i;
	for(int j=0;j<=K;j++)f[0][j]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<=K;j++){
		f[i][j]=0;
		for(int k=0;k<=min(i-1,j);k++)ADD(f[i][j],f[i-k-1][j-k]);
	}
	for(int i=1;i<=n;i++){
		int o[5];
		for(int j=0;j<=K;j++)o[j]=i+j,s[i][j]=0;
		sort(o,o+K+1,[](int x,int y){return p[x]<p[y];});
		for(int j=0;j<=K&&o[j]!=i;j++)for(int k=K;k>=o[j]-i;k--)
			ADD(s[i][k],f[n-o[j]][k-(o[j]-i)]);
		for(int j=0;j<=K;j++)s[i][j]+=s[i-1][j];
	}
	while(q--){
		ll x;int y;
		read(y),read(x);
		if(x>f[n][K]){puts("-1");continue;}
		int i=1,j=K;
		bool lop=true;
		while(lop){
			for(int k=18;k>=0;k--){
				if(i+(1<<k)-1>n)continue;
				ii JUM=s[i+(1<<k)-1][j]-s[i-1][j];
				if(x>JUM&&x<=JUM+f[n-i-(1<<k)+1][j])x-=JUM,i+=1<<k;
			}
				
//			printf("%lld:(%d,%d)\n",x,i,j);
			if(i>y){print(p[y]),putchar('\n');break;}
			int o[5];
			for(int k=0;k<=j;k++)o[k]=i+k;
			sort(o,o+j+1,[](int u,int v){return p[u]<p[v];});
//			for(int k=0;k<=j;k++)printf("%d ",o[k]);puts("");
			for(int k=0;k<=j;k++)
				if(x>f[n-o[k]][j-(o[k]-i)])x-=f[n-o[k]][j-(o[k]-i)];
				else{
					if(y<=o[k])print(p[o[k]-(y-i)]),putchar('\n'),lop=false;
					else j-=o[k]-i,i=o[k]+1;
					break;
				}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}