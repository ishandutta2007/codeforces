#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500039],st[500039],s[500039],ans[500039],h[500039],f[500039];
struct yyy {
	int x,y,num;
}sf[500039];
inline bool cmp(yyy x,yyy y) {
	return (s[x.x]^s[y.x])?(x.x<y.x):((s[x.x]&1)?x.y<y.y:x.y>y.y);
}
inline void read(int &x) {
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x) {
	if(x>9) print(x/10);
	putchar(x%10+48);
}
inline void swap(int &x,int &y) {x^=y;y^=x;x^=y;}
int main() {
	register int i,head=0,l=1,r=0,n,m,k,st[500039];
	scanf("%d",&n);
	k=sqrt(n);
	for(i=1;i<=k;i++) s[i]=1;
	for(i=k+1;i<=n;i++) s[i]=s[i-k]+1;
	for(i=1; i<=n; i++)read(a[i]);
	scanf("%d",&m);
	for(i=1; i<=m; i++) read(sf[i].x),read(sf[i].y),sf[i].num=i;
	sort(sf+1,sf+m+1,cmp);
	for(i=1; i<=m; i++) {
		while(l<sf[i].x) {
			f[a[l]]--;
			if(f[a[l]]==1) st[++head]=a[l],h[a[l]]=head;
			if(!f[a[l]]) h[st[head]]=h[a[l]],swap(st[h[a[l]]],st[head]),head--,h[a[l]]=0;
			l++;
		}
		while(r>sf[i].y){
			f[a[r]]--;
			if(f[a[r]]==1) st[++head]=a[r],h[a[r]]=head;
			if(!f[a[r]]) h[st[head]]=h[a[r]],swap(st[h[a[r]]],st[head]),head--,h[a[r]]=0;
			r--;
		}
		while(l>sf[i].x){
			f[a[--l]]++;
			if(f[a[l]]==1) st[++head]=a[l],h[a[l]]=head;
			if(f[a[l]]==2) h[st[head]]=h[a[l]],swap(st[h[a[l]]],st[head]),head--,h[a[l]]=0;
		}
		while(r<sf[i].y){
			f[a[++r]]++;
			if(f[a[r]]==1) st[++head]=a[r],h[a[r]]=head;
			if(f[a[r]]==2) h[st[head]]=h[a[r]],swap(st[h[a[r]]],st[head]),head--,h[a[r]]=0;
			//printf("%d\n",head);
		}
		if(head) ans[sf[i].num]=st[head];
	}
	for(i=1;i<=m;i++) print(ans[i]),putchar('\n');
}