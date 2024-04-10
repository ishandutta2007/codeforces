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
typedef pair<int,int> pii;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=100;
int qu;
char s[MAXN+5];
void solve(){
	scanf("%s",s+1);int n=strlen(s+1);
	if(n&1){puts("No");return;}
	int p1=0,p2=0;
	for(int i=1;i<=n;i++) if(s[i]=='(') p1=i;
	for(int i=1;i<=n;i++) if(s[i]==')') p2=i;
	if(p1==n||p2==1) puts("No");
	else puts("Yes");
}
signed main(){
	scanf("%d",&qu);while(qu--) solve();
	return 0;
}