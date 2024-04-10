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
ll s[MAXN+5];
map<ll,bool> mmp;
void solve(int l,int r){
	mmp[s[r]-s[l-1]]=1;
	if(l==r) return;
	int mid=(a[l]+a[r])>>1;
	int qwq=lower_bound(a+1,a+n+1,mid+1)-a;
	if(qwq==l||qwq==r+1) return;
	solve(l,qwq-1);solve(qwq,r);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
		mmp.clear();solve(1,n);
		while(m--){
			int x;scanf("%d",&x);
			if(mmp[x]) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}