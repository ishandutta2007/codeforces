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
int a[5];
signed main(){
	int T;scanf("%d",&T);
	while(T--){
		for(int i=1;i<=4;i++) scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=4;i++) for(int j=1;j<i;j++){
			int mn1=1e9,mn2=1e9;
			for(int k=1;k<=4;k++){
				if(k!=i&&k!=j) mn1=min(mn1,a[k]);
				else mn2=min(mn2,a[k]);
			} ans=max(ans,mn1*mn2);
		}
		printf("%d\n",ans);
	}
	return 0;
}