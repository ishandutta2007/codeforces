#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 255;

int n,m;
int a[N][N],b[N][N];
int x[N],y[N],lx[N],rx[N],ly[N],ry[N];
bool visx[N],visy[N];
pair<int,int> p[N*N];
int fx[4]={0,0,-1,1};
int fy[4]={-1,1,0,0};

void add(int x1,int y1,int val){
	b[x1][y1]=val;
	visx[x1]=true;
	visy[y1]=true;
	lx[x1]=min(lx[x1],y1);
	rx[x1]=max(rx[x1],y1);
	ly[y1]=min(ly[y1],x1);
	ry[y1]=max(ry[y1],x1);
}

bool check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j){
		cin>>a[i][j];
		x[i]=max(x[i],a[i][j]);
		y[j]=max(y[j],a[i][j]);
	}
	memset(lx,0x3f,sizeof(lx));
	memset(ly,0x3f,sizeof(ly));
	memset(rx,-0x3f,sizeof(rx));
	memset(ry,-0x3f,sizeof(ry));
	for(int i=1;i<=n;++i)p[x[i]].first=1;
	for(int i=1;i<=m;++i)p[y[i]].second=1;
	for(int i=n*m;i>=1;--i){
		if(p[i].first&&p[i].second){
			for(int j=1;j<=n;++j)
			if(!visx[j]){
				for(int k=1;k<=m;++k)
				if(!visy[k]){
					add(j,k,i);	
					break;
				}
				break;
			}
		}
		else if(p[i].first){
			for(int j=1;j<=m;++j)
			if(check(ly[j]-1,j)&&!visx[ly[j]-1]){
				add(ly[j]-1,j,i);
				break;
			}
			else if(check(ry[j]+1,j)&&!visx[ry[j]+1]){
				add(ry[j]+1,j,i);
				break;
			}
		}
		else if(p[i].second){
			for(int j=1;j<=n;++j)
			if(check(j,lx[j]-1)&&!visy[lx[j]-1]){
				add(j,lx[j]-1,i);
				break;
			}
			else if(check(j,rx[j]+1)&&!visy[rx[j]+1]){
				add(j,rx[j]+1,i);
				break;
			}
		}
		else{
			for(int j=1;j<=m;++j)
			if(check(ly[j]-1,j)&&visx[ly[j]-1]){
				int x=ly[j]-1;
				if(lx[x]-1!=j&&rx[x]+1!=j)continue;
				add(ly[j]-1,j,i);
				break;
			}
			else if(check(ry[j]+1,j)&&visx[ry[j]+1]){
				int x=ry[j]+1;
				if(lx[x]-1!=j&&rx[x]+1!=j)continue;
				add(ry[j]+1,j,i);
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(!b[i][j]){
		printf("-1");
		return 0;
	}
	for(int j=1;j<=n;++j){
		for(int k=1;k<=m;++k){
			printf("%d ",b[j][k]);
		}
		printf("\n");
	}
}