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
const int MAXN=200;
char s[MAXN+5];
const char _2020[]=" 2020";
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d%s",&n,s+1);
		if(n<=3) puts("NO");
		else{
			bool flg=0;
			for(int i=0;i<=4;i++){
				char t[5]={0};int cnt=0;
				for(int j=1;j<=i;j++) t[++cnt]=s[j];
				for(int j=n-3+i;j<=n;j++) t[++cnt]=s[j];
				bool ok=1;
				for(int j=1;j<=4;j++) ok&=(t[j]==_2020[j]);
				if(ok) flg=1;
			}
			puts((flg)?"YES":"NO");
		}
	}
	return 0;
}