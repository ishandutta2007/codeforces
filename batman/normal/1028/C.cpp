#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)201*1000)
#define INF ((int)2e9)

int n,minx[N],maxx[N],miny[N],maxy[N];
int x[N],y[N],x2[N],y2[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	minx[0]=miny[0]=INF;
	maxx[0]=maxy[0]=-INF;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>x2[i]>>y2[i];
		minx[i]=min(minx[i-1],x2[i]);
		maxx[i]=max(maxx[i-1],x[i]);
		miny[i]=min(miny[i-1],y2[i]);
		maxy[i]=max(maxy[i-1],y[i]);	
	}
	int minx2=INF,miny2=INF,maxx2=-INF,maxy2=-INF;
	for(int i=n;i>=1;i--)
	{
		int mnx=min(minx[i-1],minx2),mxx=max(maxx[i-1],maxx2);
		int mny=min(miny[i-1],miny2),mxy=max(maxy[i-1],maxy2);
		if(mxx<=mnx && mxy<=mny)return cout<<mxx<<" "<<mxy<<"\n",0;
		minx2=min(minx2,x2[i]);
		maxx2=max(maxx2,x[i]);
		miny2=min(miny2,y2[i]);
		maxy2=max(maxy2,y[i]);
	}
	return 0;
}