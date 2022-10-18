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
const int MAXN=1e6;
const int LOG_N=20;
const int MAX=(1<<LOG_N)-1;
const int MOD=1e9+7;
int n,a[MAXN+5],cnt[MAX+5],pw[MAXN+5];
int getbit(int x){int ret=0;while(x) ret++,x&=(x-1);return ret;}
int main(){
	scanf("%d",&n);
	pw[0]=1;for(int i=1;i<=MAXN;i++) pw[i]=pw[i-1]*2%MOD;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=0;i<LOG_N;i++) for(int j=MAX;~j;j--){
		if(!(j>>i&1)) cnt[j]+=cnt[j|(1<<i)];
	} int ans=0;
	for(int i=0;i<=MAX;i++){
		int num=getbit(i);
		if(num&1) ans=(ans-pw[cnt[i]]+MOD)%MOD;
		else ans=(ans+pw[cnt[i]])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}