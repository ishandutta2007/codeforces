#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=5e5;
const int DELTA=5e5+2;
int n,cnt[MAXN*2+5][2];
char s[MAXN+5];
void solve(){
	scanf("%s",s+1);n=strlen(s+1);
	int cur=0;
	for(int i=1;i<=n;i++){
		cnt[DELTA+cur][s[i]-'0']++;
		if(s[i]=='0') cur--;else cur++;
	}
	int x=0;
	for(int i=1;i<=n;i++){
		if(cnt[x+DELTA][0]&&cnt[x-1+DELTA][1]) cnt[x+DELTA][0]--,x--,putchar('0');
		else if(cnt[x+DELTA][1]) cnt[x+DELTA][1]--,x++,putchar('1');
		else cnt[x+DELTA][0]--,x--,putchar('0');
	}
	printf("\n");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}