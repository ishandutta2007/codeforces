#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=150000;

int n;
int x1[N], y1[N], x2[N], y2[N];
int prefx1[N], prefy1[N], prefx2[N], prefy2[N];
int sufx1[N], sufy1[N], sufx2[N], sufy2[N];

int32_t main()
{
	IOS;
	cin>>n;
	prefx1[0]=prefy1[0]=sufx1[n+1]=sufy1[n+1]=-1e9;
	prefx2[0]=prefy2[0]=sufx2[n+1]=sufy2[n+1]=1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		prefx1[i]=max(prefx1[i-1], x1[i]);
		prefy1[i]=max(prefy1[i-1], y1[i]);
		prefx2[i]=min(prefx2[i-1], x2[i]);
		prefy2[i]=min(prefy2[i-1], y2[i]);
	}
	for(int i=n;i>=1;i--)
	{
		sufx1[i]=max(sufx1[i+1], x1[i]);
		sufy1[i]=max(sufy1[i+1], y1[i]);
		sufx2[i]=min(sufx2[i+1], x2[i]);
		sufy2[i]=min(sufy2[i+1], y2[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int lx=max(prefx1[i-1], sufx1[i+1]);
		int ly=max(prefy1[i-1], sufy1[i+1]);
		int rx=min(prefx2[i-1], sufx2[i+1]);
		int ry=min(prefy2[i-1], sufy2[i+1]);
		if(lx>rx || ly>ry)
			continue;
		cout<<lx<<" "<<ly;
		return 0;
	}
	return 0;
}