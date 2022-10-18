#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
int a[6],c[4],p[6],num[4];
void solve(){
	for(int i=1;i<=3;i++) scanf("%d",&c[i]);
	for(int i=1;i<=5;i++) scanf("%d",&a[i]);
	if(c[1]<a[1]){puts("NO");return;} c[1]-=a[1];
	if(c[2]<a[2]){puts("NO");return;} c[2]-=a[2];
	if(c[3]<a[3]){puts("NO");return;} c[3]-=a[3];
	if(c[1]<a[4]) c[3]-=(a[4]-c[1]);
	if(c[2]<a[5]) c[3]-=(a[5]-c[2]);
	if(c[3]<0) puts("NO");
	else puts("YES");
}
signed main(){
	int T;scanf("%d",&T);
	while(T--) solve();
	return 0;
}