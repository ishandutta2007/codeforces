#include<cstdio>
#include<queue>
#include<cmath>
#define N 100039
#define K 359
#define I inline
using namespace std;
int n,m,k,op,x,y,z,fr,en,st[N],sh,now,a[N],ans,lastans;
int f[K][N];
deque<int> q[K];
I void make(int &x){x=(x+lastans-1)%n+1;}
I void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&n);k=sqrt(n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),f[i/k][a[i]]++,q[i/k].push_back(a[i]);scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&op,&x,&y);make(x);make(y);x>y&&(swap(x,y),0);fr=y/k*k;en=x/k*k+k-1;
		if(op==1){
			if(x/k==y/k){
				for(i=fr;i<=y;i++) st[++sh]=q[x/k].front(),q[x/k].pop_front();
				for(i=1;i<y-x+1;i++) swap(st[sh-i+1],st[sh-i]);
				while(sh) q[x/k].push_front(st[sh--]);continue;
			}
			for(i=fr;i<=y;i++) st[++sh]=q[y/k].front(),q[y/k].pop_front();now=st[sh--];
			while(sh) q[y/k].push_front(st[sh--]);f[y/k][now]--,f[x/k][now]++;//printf("%d %d %d\n",x+1,en,q[x/k].size());
			for(i=en;i>=x;i--) st[++sh]=q[x/k].back(),q[x/k].pop_back();st[++sh]=now;
			while(sh) q[x/k].push_back(st[sh--]);
			for(i=x/k;i<y/k;i++) now=q[i].back(),q[i].pop_back(),f[i][now]--,f[i+1][now]++,q[i+1].push_front(now);
		}
		else{
			scanf("%d",&z);make(z);ans=0;
			if(x/k==y/k){
				for(i=fr;i<=y;i++) st[++sh]=q[x/k].front(),q[x/k].pop_front();
				for(i=x;i<=y;i++) ans+=(st[sh]==z),q[x/k].push_front(st[sh--]);
				while(sh) q[x/k].push_front(st[sh--]);printf("%d\n",lastans=ans);continue;
			}
			for(i=x/k+1;i<y/k;i++) ans+=f[i][z];
			for(i=fr;i<=y;i++) st[++sh]=q[y/k].front(),q[y/k].pop_front();
			while(sh) ans+=(st[sh]==z),q[y/k].push_front(st[sh--]);
			for(i=x;i<=en;i++) st[++sh]=q[x/k].back(),q[x/k].pop_back();
			while(sh) ans+=(st[sh]==z),q[x/k].push_back(st[sh--]);
			printf("%d\n",lastans=ans);
		}
	}
}