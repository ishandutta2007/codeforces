#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int M = 5e2+5;

int T,n,m;
int a[N],id[N],p[N],las[M],fir[M];
bool use[M][M];

bool cmp(int x,int y){
	return a[x]<a[y]||(a[x]==a[y]&&x>y);
}

map<int,int> cnt[M]; 

int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n*m;++i)scanf("%d",&a[i]),id[i]=i;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		use[i][j]=0;
		sort(id+1,id+n*m+1,cmp);
		int ans=0;
		for(int i=1;i<=n*m;++i){
			int x=(i-1)/m+1;
			int y=i-(x-1)*m;
			if(y==m)las[x]=a[id[i]];
			if(y==1)fir[x]=a[id[i]];
			cnt[x][a[id[i]]]++;
			p[id[i]]=i;
		}
		for(int i=1;i<=n*m;++i){
			bool flag=0;
			for(int x=1;x<=n;++x)
			if(las[x]==a[i]&&cnt[x][a[i]]>0){
				int y=m;
				while(use[x][y])--y;
				for(int j=1;j<y;++j)if(use[x][j])++ans;
				use[x][y]=1;
				--cnt[x][a[i]];
				flag=1;
				break;
			}
			if(flag)continue;
			for(int x=1;x<=n;++x)
			if(fir[x]==a[i]&&cnt[x][a[i]]>0){
				int y=cnt[x][a[i]];
				use[x][y]=1;
				--cnt[x][a[i]];
				flag=1;
				break;
			}
			if(flag)continue;
			int x=(p[i]-1)/m+1;
			int y=p[i]-(x-1)*m;
			for(int j=1;j<y;++j)if(use[x][j])++ans;
			use[x][y]=1;
		}
		for(int i=1;i<=n;++i)cnt[i].clear(),las[i]=fir[i]=0;
		cout<<ans<<endl;
	}
}