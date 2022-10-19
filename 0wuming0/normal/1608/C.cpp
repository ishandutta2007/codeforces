#include<bits/stdc++.h>
#define dbg(x) cout << #x << "===" << x << endl
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9+7;
const int INF = 2e18;
const double PI=acos(-1);
const double eps=1e-7;
int read()
{
    int s=0,bj=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return bj?-s:s;
}
map<int,int> mp1,mp2;
int a[maxn],b[maxn];
int pos[maxn];
bool cmp(int x,int y) {
	return a[x]<a[y];
}
int ans[maxn];
signed main() 
{
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		mp1.clear();
		mp2.clear(); 
		for(int i=1;i<=n;i++) a[i]=read(),mp1[a[i]]=i;
		for(int i=1;i<=n;i++) b[i]=read(),mp2[b[i]]=i;
		for(int i=1;i<=n;i++) pos[i]=i;
		sort(pos+1,pos+1+n,cmp);
		int x=0,y=0;
		for(int i=1;i<=n;i++) {
			x=max(x,a[pos[i]]);
			y=max(y,b[pos[i]]);
			while(1) {
				bool ok=1;
				if(mp1.size()!=0) {
					if(mp1.begin()->first<=x) {
						ok=0;
						y=max(y,b[mp1.begin()->second]);
						mp1.erase(mp1.begin());
					}
				}
				if(mp2.size()!=0) {
					if(mp2.begin()->first<=y) {
						ok=0;
						x=max(x,a[mp2.begin()->second]);
						mp2.erase(mp2.begin());
					}
				}
				if(ok)break;
			}
			if(mp1.size()+mp2.size())
			{
				ans[pos[i]]=0;
			}
			else
			{
				ans[pos[i]]=1;
			}
		}
		for(int i=1;i<=n;i++)printf("%d",ans[i]);
		printf("\n"); 
	}
    return 0;
}