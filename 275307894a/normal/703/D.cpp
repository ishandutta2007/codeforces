#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[1000039],nows[1000039],tots[1000039],head,l,r,mid,f[1000039],g[1000039],ans[1000039],q[1000039],b[1000039];
struct yyy{int x,y,num;}s[1000039];
inline bool cmp(yyy x,yyy y){return x.y<y.y;}
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
inline void get(int x,int y){while(x<=n)f[x]^=y,x+=x&-x;}
inline int find(int x){int ans=0;while(x) ans^=f[x],x-=x&-x;return ans;}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);
	for(i=1;i<=n;i++) read(a[i]),nows[i]=a[i];
	sort(nows+1,nows+n+1); 
	for(i=1;i<=n;i++){
		tots[i]=tots[i-1];
		if(nows[i]!=nows[i-1]) tots[i]++;
	}
	for(i=1;i<=n;i++){
		l=0;r=n+1;
		while(l+1<r){
			mid=(l+r)>>1;
			if(nows[mid]<a[i]) l=mid;
			else r=mid;
		}
		b[i]=tots[r];
		q[i]=q[i-1]^a[i];
	}
	read(m);
	for(i=1;i<=m;i++)read(s[i].x),read(s[i].y),s[i].num=i,ans[i]=q[s[i].y]^q[s[i].x-1];
	sort(s+1,s+m+1,cmp);
	for(i=1;i<=n;i++){
		if(g[b[i]]) get(g[b[i]],a[i]);
		g[b[i]]=i;get(i,a[i]);
		while(head<m&&s[head+1].y==i) head++,ans[s[head].num]^=find(s[head].y)^find(s[head].x-1);
	}
	for(i=1;i<=m;i++) print(ans[i]),putchar('\n');
}