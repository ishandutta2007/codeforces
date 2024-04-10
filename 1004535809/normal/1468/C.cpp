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
const int MAXN=5e5;
int num=0,a[MAXN+5];
signed main(){
	int qu;scanf("%d",&qu);
	set<pii> s1,s2;
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){++num;scanf("%d",&a[num]);s1.insert(mp(a[num],-num));s2.insert(mp(num,num));}
		else if(opt==2){pii p=*s2.begin();s2.erase(p);printf("%d ",p.fi);s1.erase(s1.find(mp(a[p.fi],-p.fi)));}
		else{pii p=*s1.rbegin();s1.erase(p);printf("%d ",-p.se);s2.erase(mp(-p.se,-p.se));}
	}
	return 0;
}