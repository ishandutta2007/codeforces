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
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int ALPHA=24;
const int LIM=(1<<ALPHA)-1;
int n,cnt[LIM+5],ans=0;char s[4];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);int msk=0;
		for(int j=1;j<=3;j++) msk|=(1<<(s[j]-'a'));
		cnt[LIM^msk]++;
	}
	for(int i=0;i<ALPHA;i++) for(int j=LIM;~j;j--)
		if(!(j>>i&1)) cnt[j]+=cnt[j^(1<<i)];
	for(int i=0;i<=LIM;i++) ans^=(n-cnt[i])*(n-cnt[i]);
	printf("%d\n",ans);
	return 0;
}