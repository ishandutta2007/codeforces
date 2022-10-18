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
const int MAXN=1e5;
int n,m,a[MAXN+5];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int cur=n;while(cur&&a[cur]==cur) cur--;
		double p=1;
		for(int i=1;i<=m;i++){
			int x;double pr;scanf("%d%lf",&x,&pr);
			if(x>=cur) p*=(1.0-pr);
		}
		if(!cur){puts("1.0000000000");continue;}
		printf("%.10lf\n",1-p);
	}
	return 0;
}