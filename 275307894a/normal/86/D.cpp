#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,k,ks,f[1000039],s[200039],q[200039],tot,pus,a[200039],l=1,r=0,ans[200039];
struct yyy{
	long long x,y,num;
}sf[200039];
inline bool cmp(yyy x,yyy y){
	return (s[x.x]^s[y.x])?(x.x<y.x):((s[x.x]&1)?x.y<y.y:x.y>y.y);
}
inline void read(long long &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(register long long x){
    if(x>9) print(x/10);
    putchar(x%10+48);
}
int main(){
	register int i,j;
	scanf("%lld%lld",&n,&m);
	ks=sqrt(n);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=ks;i++) s[i]=1;
	for(i=ks+1;i<=n;i++) s[i]=s[i-ks]+1;
	for(i=1;i<=m;i++){
		read(sf[i].x);read(sf[i].y);
		sf[i].num=i;
	}
	sort(sf+1,sf+m+1,cmp);
	for(i=1;i<=m;i++){
		while(sf[i].x<l) l--,tot+=(f[a[l]]*2+1)*a[l],f[a[l]]++;
		while(sf[i].x>l) tot-=(f[a[l]]*2-1)*a[l],f[a[l]]--,l++;
		while(sf[i].y<r) tot-=(f[a[r]]*2-1)*a[r],f[a[r]]--,r--;
		while(sf[i].y>r) r++,tot+=(f[a[r]]*2+1)*a[r],f[a[r]]++;
		ans[sf[i].num]=tot;
	}
	for(i=1;i<=m;i++) print(ans[i]),putchar('\n');
}