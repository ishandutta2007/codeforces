//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
const int maxn = 100111;
int n, m;
int f[maxn];
vector<pair<int,pair<int,int> > > E;
int gf(int x) {return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	for (int i=0; i<maxn; i++) f[i] = i;
	scanf("%d%d", &n, &m);
	int X, Y, T;
	scanf("%d%d%d", &X, &Y, &T);
	for (int i=2; i<=m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		E.PB(MP(w, MP(x, y)));
	}
	sort(E.begin(), E.end());
	int ans = 1e9;
	for (auto e : E)
	{
		int x = e.SS.FF;
		int y = e.SS.SS;
		x = gf(x);
		y = gf(y);
		f[x] = y;
		if (gf(X)==gf(Y))
		{
			ans = e.FF;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}