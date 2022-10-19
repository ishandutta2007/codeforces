#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define CI const int &
using namespace std;
int n,m,k,x,y,z,t,a[200039],f2[800039],f1[800039],ans1,ans2,ans3,ans4;
char _s;
inline void js(int l,int r,int now){
	if(l==r){f1[now]=f2[now]=a[l];return;}
	int m=l+r>>1;js(l,m,now<<1);js(m+1,r,now<<1|1);
	f1[now]=min(f1[now<<1],f1[now<<1|1]);
	f2[now]=max(f2[now<<1],f2[now<<1|1]);
}
inline int find1(int x,int y,CI l=0,CI r=n,CI now=1){
	if(x>y) return 0;
	if(x<=l&&r<=y) return f1[now];
	int m=l+r>>1,f1=1e9,f2=1e9;
	if(x<=m) f1=find1(x,y,l,m,now<<1);
	if(y>m) f2=find1(x,y,m+1,r,now<<1|1);
	return min(f1,f2);
}
inline int find2(int x,int y,CI l=0,CI r=n,CI now=1){
	if(x>y) return 0;
	if(x<=l&&r<=y) return f2[now];
	int m=l+r>>1,f1=-1e9,f2=-1e9;
	if(x<=m) f1=find2(x,y,l,m,now<<1);
	if(y>m) f2=find2(x,y,m+1,r,now<<1|1);
	return max(f1,f2);
}
int main(){
	//freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			_s=getchar();
			while(_s!='+'&&_s!='-') _s=getchar();
			a[i]=a[i-1]+(_s=='+'?1:-1);
		}
		js(0,n,1);
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(y==n){ans1=find2(0,x-1);ans2=find1(0,x-1);printf("%d\n",ans1-ans2+1);continue;}
			ans1=find2(0,x-1),ans2=find2(y+1,n),ans3=find1(0,x-1),ans4=find1(y+1,n);
			ans1=max(ans1,ans2-(a[y]-a[x-1]));ans3=min(ans3,ans4-(a[y]-a[x-1]));
			printf("%d\n",ans1-ans3+1);
		}
	}
}