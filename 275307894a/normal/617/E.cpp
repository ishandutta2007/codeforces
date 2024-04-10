#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k,ks,h[100039],q[100039],a[100039],l,r,f[2000039];
long long tot,ans[100039];
struct yyy{
	int x,y,num;
}s[100039];
inline void read(register int &x) {
	x=0;register char s=getchar();
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(register long long x) {
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
inline bool cmp(yyy x,yyy y){return h[x.x]==h[y.x]?((h[x.x]&1)?x.y<y.y:x.y>y.y):x.x<y.x;}
int main(){
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	ks=sqrt(n);
	for(i=1;i<=ks;i++) h[i]=1;
	for(i=ks+1;i<=n;i++) h[i]=h[i-ks]+1;
	for(i=1;i<=n;i++) read(q[i]),a[i]=a[i-1]^q[i];
	for(i=1;i<=m;i++) read(s[i].x),read(s[i].y),s[i].num=i;
	sort(s+1,s+m+1,cmp);
	l=1;
	for(i=1;i<=m;i++){
		while(l<s[i].x-1) --f[a[l]],tot-=f[a[l++]^k];
		while(r>s[i].y) --f[a[r]],tot-=f[a[r--]^k];
		while(l>s[i].x-1) tot+=f[a[--l]^k],++f[a[l]];
		while(r<s[i].y) tot+=f[a[++r]^k],++f[a[r]];
		ans[s[i].num]=tot;
	}
	for(i=1;i<=m;i++) print(ans[i]),putchar('\n');
}