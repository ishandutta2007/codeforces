#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n,m,Q;
char s[N][N];
pair<int,int> q[N*N*2];
int d[N][N];
int fx[4]={0,0,-1,1};
int fy[4]={-1,1,0,0};

int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;++j)s[i][j]-='0';
	}
	int L=N*N,R=N*N-1;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		for(int k=0;k<4;++k){
			int x=i+fx[k],y=j+fy[k];
			if(x<1||x>n||y<1||y>m)continue;
			if(s[x][y]==s[i][j]){
				q[++R]={i,j};
				d[i][j]=1;
				break;
			}
		}
	}
	while(L<=R){
		pair<int,int> r=q[L++];
		int i=r.first,j=r.second;
		for(int k=0;k<4;++k){
			int x=i+fx[k],y=j+fy[k];
			if(x<1||x>n||y<1||y>m)continue;
			if(d[x][y])continue;
			if(s[x][y]==s[i][j]){
				d[x][y]=d[i][j];
				q[--L]={x,y};
			}
			else{
				d[x][y]=d[i][j]+1;
				q[++R]={x,y};
			}
		}
	}
	for(int i=1,x,y;i<=Q;++i){
		ll p;
		scanf("%d%d%lld",&x,&y,&p);
		if(!d[x][y]||p<d[x][y])putchar(s[x][y]+'0');
		else putchar(s[x][y]^(p-d[x][y]+1&1)+'0');
		printf("\n");
	}
}