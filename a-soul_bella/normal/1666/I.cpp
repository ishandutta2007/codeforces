#include <bits/stdc++.h>
using namespace std;
int s[17][17][17][17];
int X,Y,XX,YY,n,m;
const int TEST=0;
inline int D(int x,int y)
{
	return max(x,y)-min(x,y);
}
inline int sc(int x,int y)
{
	cout << "SCAN " << x << ' ' << y << endl;
	if(TEST) return D(x,X)+D(x,XX)+D(y,Y)+D(y,YY);
	cin >> x;
	return x;
}
inline int dig(int x,int y)
{
	cout << "DIG " << x << " " << y << endl;
	if(TEST) return x==X&&y==Y||x==XX&&y==YY;
	cin >> x;
	return x;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		if(TEST)
			cin >> X >> Y >> XX >> YY;
		vector <pair<int,int> > v;
		int X,Y;
		X=sc(1,1)+4;
		Y=sc(1,m)-m-m+2;
		int sx=(X+Y)/2,sy=(X-Y)/2;
		int midx=sx/2,midy=sy/2;
		int dx=sc(midx,1)-sy+2;
		int dy=sc(1,midy)-sx+2;
		int mnx=(sx-dx)/2,mxx=(sx+dx)/2;
		int mny=(sy-dy)/2,mxy=(sy+dy)/2;
		if(dig(mnx,mny)) dig(mxx,mxy);
		else dig(mxx,mny),dig(mnx,mxy);
	}
	return 0;
}