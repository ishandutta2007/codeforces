#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
/*const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
inline int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/

void solve()
{
	int x,y;
	readint(x),readint(y);
	vector<int> a,b;
	for(int i=0;i<30;++i)
	{
		if(x&(1<<i))a.pb(i);
		if(y&(1<<i))b.pb(i);
	}
	while(!a.empty() && !b.empty() && a.back()==b.back())a.pop_back(),b.pop_back();
	if(a.size()<b.size()){printf("NO\n");return;}
	if(a.empty()){printf("YES\n");return;}
	if(b.empty()){printf("NO\n");return;}
	if(a.back()>b.back()){printf("NO\n");return;}
	b.pop_back();
	while(a.size()>b.size())a.pop_back();
	for(int i=0;i<a.size();++i)
		if(a[i]>b[i]){printf("NO\n");return;}
	printf("YES\n");
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}