#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,k,a[205],f[205][105],x[105],y[105];
//void u(int &x,int y){if(y>x)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;++i){
			scanf("%d%d",x+i,y+i);
			if(x[i]>y[i])swap(x[i],y[i]);
			a[x[i]]=a[y[i]]=1;
		}
		int o=1;
		for(int i=k+1;i<=n;++i){
			while(a[o])++o;
			x[i]=o;
			a[o]=1;
		}
		
		for(int i=k+1;i<=n;++i){
			while(a[o])++o;
			y[i]=o;
			a[o]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]>x[i]&&x[j]<y[i]&&y[j]>y[i])++cnt;
				if(x[i]>x[j]&&x[i]<y[j]&&y[i]>y[j])++cnt;
			}
		}
		printf("%d\n",cnt);
		/*for(int i=0;i<=n*2+1;++i){
			for(int j=0;j<=n+1;++j)f[i][j]=-orz;
		}
		f[0][0]=0;
		for(int i=1;i<=k;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			a[x]=1,a[y]=-1;
		}
		for(int i=1;i<=n*2;++i){
			if(a[i]>=0){
				for(int j=0;j<n;++j)u(f[i][j+1],f[i-1][j]-j*a[i]);
			}
			if(a[i]<=0){
				for(int j=1;j<=n;++j)u(f[i][j-1],f[i-1][j]+j-1);
			}
		}
		printf("%d\n",f[n*2][0]);*/
	}
				
    return 0;
}