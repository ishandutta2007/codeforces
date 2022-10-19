#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 400000
#define W 400000
#define mod 998244353
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,k,A[N+5],ans=1e9,now,pus;ll F[N+5<<2],sum[N+5<<2];
I void pushF(int l,int r,int x){F[x]+=F[x>>1];sum[x]+=F[x>>1]*(r-l+1);}
I void push(int l,int r,int x){if(!F[x]) return;int m=l+r>>1;pushF(l,m,x<<1);pushF(m+1,r,x<<1|1);F[x]=0;}
I void get(int x,int y,int z,int l=0,int r=W,int now=1){
	if(x<=l&&r<=y){F[now]+=z;sum[now]+=z*(r-l+1);return;}int m=l+r>>1;push(l,r,now);
	x<=m&&(get(x,y,z,l,m,now<<1),0);y>m&&(get(x,y,z,m+1,r,now<<1|1),0);sum[now]=sum[now<<1]+sum[now<<1|1];
}
I int find(int z,int l=0,int r=W,int now=1){
	if(l==r) return l;int m=l+r>>1;push(l,r,now);/*printf("%d %d %d %d\n",l,r,sum[now],z);*/return sum[now<<1]>=z?find(z,l,m,now<<1):find(z-sum[now<<1],m+1,r,now<<1|1);
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&k);for(i=1;i<=n;i++) scanf("%d",&A[i]);sort(A+1,A+n+1);
	get(0,0,1);for(i=n;i;i--){
		now=find(1);get(now,now,-1);/*printf("%d\n",find(2));*/(A[i]>2)&&(get(now+2,now+1+(A[i]-1)/2,1),0);A[i]>1&&(get(now+2,now+1+A[i]/2,1),0);
		if(sum[1]>=k)now=find(k),ans=min(ans,now);//printf("%d\n",ans);
	}
	printf("%d\n",(ans==1e9)?-1:ans); 
}