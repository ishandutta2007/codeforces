#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6+5;
 
#define ls (x<<1)
#define rs (x<<1|1)
 
int T;
int h,g;
int a[N];
int id[N],p[N],res[N];
ll ans;
 
bool cmp(int x,int y){
	return a[x]>a[y];
}
 
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&h,&g);
		ans=0;
		for(int i=1;i<(1<<h);++i){
			scanf("%d",&a[i]);
			ans+=a[i];
			id[i]=i;
		}
		sort(id+1,id+(1<<h),cmp);
		for(int i=1;i<(1<<h);++i)p[id[i]]=i;
		for(int i=1,cnt=0;cnt<(1<<h)-(1<<g);++i){
			int x=id[i],m;
			static int q[30];
			q[m=1]=x;
			while(a[ls]||a[rs]){
				if(a[ls]>a[rs])x=ls;
				else x=rs;
				q[++m]=x;
			}
			q[m+1]=0;
			if(q[m]<(1<<g))continue;
			res[++cnt]=q[1];
			ans-=a[q[1]];
			for(int j=1;j<=m;++j){
				a[q[j]]=a[q[j+1]];
				p[q[j]]=p[q[j+1]];
				id[p[q[j]]]=q[j];
			}
		}
		for(int i=1;i<(1<<h);++i)a[i]=0;
		printf("%lld\n",ans);
		for(int i=1;i<=(1<<h)-(1<<g);++i)printf("%d ",res[i]);
		printf("\n");
	}
}