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
int n,a[MAXN+5];
map<char,int> mmp;
bool sgn[MAXN+5];
int pl[MAXN+5],pr[MAXN+5],pc=0;
ll pm[MAXN+5],dp[MAXN+5];int pre[MAXN+5];
void solve(int l,int r){
	if(l>r) return;
	pc=0;int lst=l-1;ll mul=1;
	for(int i=l;i<=r;i++){
		if(a[i]==1){
			if(lst+1<=i-1) pl[++pc]=lst+1,pr[pc]=i-1,pm[pc]=mul;
			mul=1;lst=i;
		} else {
			mul*=a[i];if(mul>1e9) mul=1e9;
		}
	}
	if(lst!=r) pl[++pc]=lst+1,pr[pc]=r,pm[pc]=mul;
//	for(int i=1;i<=pc;i++) printf("%d %d %d\n",pl[i],pr[i],pm[i]);
	pr[0]=l-1;for(int i=1;i<=pc;i++) dp[i]=0;
	mul=1;
	for(int i=1;i<=pc;i++){
		mul*=pm[i];if(mul>1e9) mul=1e9;
	}
	if(mul==1e9){
		pre[pc]=1;
	}
	else{
		for(int i=1;i<=pc;i++){
			mul=1;
			for(int j=i;j>=1;j--){
				mul*=pm[j];
				if(dp[i]<dp[j-1]+pl[j]-pr[j-1]-1+mul){
					dp[i]=dp[j-1]+pl[j]-pr[j-1]-1+mul;
					pre[i]=j;
				}
			}
//			printf("%d %lld %d\n",i,dp[i],pre[i]);
		}
	}
	for(int i=l;i<pl[1];i++) sgn[i]=1;
	for(int i=pr[pc];i<r;i++) sgn[i]=1;
	int cur=pc;
	while(cur){
		int t=pre[cur];//printf("%d\n",t);
		for(int i=pr[t-1];i<pl[t];i++) sgn[i]=1;cur=t-1;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);mmp['+']=0;mmp['-']=1;mmp['*']=2;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	char opt[4];scanf("%s",opt+1);int len=strlen(opt+1);
	int msk=0;for(int i=1;i<=len;i++) msk|=1<<mmp[opt[i]];
	if(msk==1||msk==2||msk==4){
		for(int i=1;i<=n;i++){
			printf("%d",a[i]);if(i!=n) printf("%s",opt+1);
		}
	} else if(msk==3){
		for(int i=1;i<=n;i++){
			printf("%d",a[i]);if(i!=n) putchar('+');
		}
	} else if(msk==6){
		bool hav=0;printf("%d",a[1]);
		for(int i=2;i<=n;i++){
			if(!a[i]&&!hav) hav=1,putchar('-');
			else putchar('*');
			printf("%d",a[i]);
		}
	} else {
		for(int i=1;i<=n;i++){
			if(!a[i]){
				if(i!=1) sgn[i-1]=1;
				if(i!=n) sgn[i]=1;
			}
		}
		int pre=0;
		for(int i=1;i<=n;i++){
			if(!a[i]) solve(pre+1,i-1),pre=i;
		}
		solve(pre+1,n);
		for(int i=1;i<n;i++){
			printf("%d",a[i]);
			if(sgn[i]) putchar('+');
			else putchar('*');
		} printf("%d",a[n]);
	}
	return 0;
}
/*
12
1 1 2 3 1 3 1 1 1 0 1 1
+*

18
1 2 3 1 1 2 1 1 1 1 1 1 1 1 1 1 1 2
+*
*/
//