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
const int MAXN=1e3;
char s[MAXN+5],t[MAXN+5];
signed main(){
	int qu;scanf("%d",&qu);
	while(qu--){
		int n;scanf("%d%s%s",&n,s+1,t+1);
		int r=0,b=0;
		for(int i=1;i<=n;i++){
			if(s[i]>t[i]) r++;
			if(s[i]<t[i]) b++;
		}
		if(r>b) puts("RED");
		else if(r==b) puts("EQUAL");
		else puts("BLUE");
	}
	return 0;
}