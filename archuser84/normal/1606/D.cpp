///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define F first
#define S second
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 5e5+10;
vector<int> mn1[N], mn2[N], mx1[N], mx2[N];
vector<int> a[N];
pii ord[N];
int n, m;

int ok(int x)
{
	static int Mx1[N], Mn1[N], Mx2[N], Mn2[N];
	Mx1[1] = mx1[x][0]; Loop(j,2,m) Mx1[j] = max(Mx1[j-1], mx1[x][j-1]);
	Mn1[1] = mn2[x][0]; Loop(j,2,m) Mn1[j] = min(Mn1[j-1], mn2[x][j-1]);
	Mx2[m-1] = mx2[x][m-1]; LoopR(j,1,m-1) Mx2[j] = max(Mx2[j+1], mx2[x][j]);
	Mn2[m-1] = mn1[x][m-1]; LoopR(j,1,m-1) Mn2[j] = min(Mn2[j+1], mn1[x][j]);
	
	Loop(j,1,m)
	{
		if(Mx1[j] < Mn1[j] && Mx2[j] < Mn2[j])
			return j;
	}

	return 0;
}

bool ans[N];

void solve()
{
	cin >> n >> m;
	Loop(i,0,n)
	{
		a[i].resize(m);
		mn1[i].resize(m);
		mx1[i].resize(m);
		mn2[i].resize(m);
		mx2[i].resize(m);
		Loop(j,0,m) cin >> a[i][j];
		ord[i] = {a[i][0], i};
	}
	sort(ord,ord+n);


	Loop(j,0,m) mn1[1][j] = mx1[1][j] = a[ord[0].S][j];
	Loop(i,1,n-1){
		Loop(j,0,m)
			mn1[i+1][j] = min(mn1[i][j], a[ord[i].S][j]),
			mx1[i+1][j] = max(mx1[i][j], a[ord[i].S][j]);
	}

	Loop(j,0,m) mn2[n-1][j] = mx2[n-1][j] = a[ord[n-1].S][j];
	LoopR(i,1,n-1){
		Loop(j,0,m)
			mn2[i][j] = min(mn2[i+1][j], a[ord[i].S][j]),
			mx2[i][j] = max(mx2[i+1][j], a[ord[i].S][j]);
	}

	Loop(i,1,n)
	{
		if(ok(i))
		{
			cout << "YES\n";
			Loop(j,0,i) ans[ord[j].S] = 1;
			Loop(j,i,n) ans[ord[j].S] = 0;
			Loop(i,0,n) cout << ("R\0B"+2*ans[i]);
			cout << ' ' << ok(i) << '\n';
			return;
		}
	}

	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}