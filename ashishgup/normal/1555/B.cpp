#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int W, H;
int x1, y1, x2, y2;
int w, h;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> W >> H;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> w >> h;
		int w1 = (x2 - x1);
		int h1 = (y2 - y1);
		if(w + w1 > W && h + h1 > H)
		{
			cout << -1 << endl;
			continue;
		}
		int ans1 = 2e9, ans2 = 2e9, ans3 = 2e9, ans4 = 2e9;
		if(w + w1 <= W)
		{
			ans1 = min(ans1, max(0LL, w - x1)); //bottom left
			ans2 = min(ans2, max(0LL, x2 - (W - w))); //bottom right
			ans3 = min(ans3, max(0LL, w - x1)); //top left
			ans4 = min(ans4, max(0LL, x2 - (W - w))); //top right
		}
		if(h + h1 <= H)
		{
			ans1 = min(max(0LL, h - y1), ans1); //bottom left
			ans2 = min(max(0LL, h - y1), ans2); //bottom right
			ans3 = min(max(0LL, y2 - (H - h)), ans3); //top left
			ans4 = min(max(0LL, y2 - (H - h)), ans4); //top right
		}
		double ans = (double) min({ans1, ans2, ans3, ans4});
		cout << fixed << setprecision(9) << ans << endl;
	}
	return 0;
}