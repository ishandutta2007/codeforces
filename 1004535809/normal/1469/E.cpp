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
const int MAXN=1e6;
const int MAXT=(1<<20)-1;
bool vis[MAXT+5];
int n,k;char s[MAXN+5];
void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	if(k<=20){
		for(int i=1;i<=n-k+1;i++){
			int msk=0;
			for(int j=i;j<=i+k-1;j++) msk|=((s[j]-'0')<<(i+k-1-j));
			msk=((1<<k)-1)^msk;vis[msk]=1;
		}
		bool flg=0;
		for(int i=0;i<(1<<k);i++){
			if(!vis[i]){
				printf("YES\n");
				for(int j=k-1;~j;j--) printf("%d",i>>j&1);
				printf("\n");flg=1;break;
			}
		}
		if(!flg) puts("NO");
		for(int i=1;i<=n-k+1;i++){
			int msk=0;
			for(int j=i;j<=i+k-1;j++) msk|=((s[j]-'0')<<(i+k-1-j));
			msk=((1<<k)-1)^msk;vis[msk]=0;
		}
	} else {
		printf("YES\n");
		for(int i=1;i<=k-20;i++) printf("0");
		int cur=1;vector<int> msks;
		for(int i=1;i<=n-k+1;i++){
			if(cur<i) cur=i;
			while(cur<=n&&s[cur]=='1') cur++;cur--;
//			printf("%d %d\n",i,cur);
			if(cur>=i+(k-20)-1){
				int msk=0;
				for(int j=i+(k-20);j<=i+k-1;j++) msk|=((s[j]-'0')<<(i+k-1-j));
//				printf("%d\n",msk);
				msk=MAXT^msk;msks.pb(msk);vis[msk]=1;
			}
		}
		for(int i=0;i<(1<<20);i++){
			if(!vis[i]){
				for(int j=19;~j;j--) printf("%d",i>>j&1);
				printf("\n");break;
			}
		}
		ffe(it,msks) vis[*it]=0;
	}
}
signed main(){
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}
/*
1
22 21
1111111111111111111110
*/