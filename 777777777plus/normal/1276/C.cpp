#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;

int n,a[N];
vector<int>del[N],ans[N];
struct nd{
	int c,w;
	friend bool operator < (nd a,nd b){
		return a.c>b.c||(a.c==b.c&&a.w<b.w);
	}
}b[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m=0;
	for(int i=1;i<=n;++i){
		if(a[i]==b[m].w)b[m].c++;
		else{
			++m;
			b[m].c=1;
			b[m].w=a[i];
		}
	}
	sort(b+1,b+m+1);
	int ansa=0,ansb=0,tmpn=n;
	for(int i=n;i>=1;--i){
		static int t=1;
		tmpn-=(t-1);
		while(t<=m&&b[t].c>i){
			tmpn-=b[t++].c-i;
		}
		int j=tmpn/i;
		if(i<=j&&i*j>ansa*ansb){
			ansa=i;
			ansb=j;
		}
	}
	for(int i=0;i<ansa;++i)ans[i].resize(ansb);
	for(int i=1;i<=m;++i){
		nd x=b[i];
		x.c=min(x.c,ansa);
		static int x1=0,y1=0;
		for(int j=1;j<=x.c;++j){
			x1=(x1+1)%ansa;
			y1=(y1+1)%ansb;
			if(ans[x1][y1]){
				x1=(x1+1)%ansa;
			}
			ans[x1][y1]=x.w;
		}
	}
	printf("%d\n",ansa*ansb);
	printf("%d %d\n",ansa,ansb);
	for(int i=0;i<ansa;++i){
		for(int j=0;j<ansb;++j){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}