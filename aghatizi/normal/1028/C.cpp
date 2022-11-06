#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define y1 shitekhar

const int maxn = 2e5 + 20;

int x1[maxn] , y1[maxn] , x2[maxn] , y2[maxn];

int l[maxn] , r[maxn] , x[maxn] , n;

void f(int ind)
{
	int nowx1 = -2e9 , nowx2 = 2e9 , nowy1 = -2e9 , nowy2 = 2e9;

	for(int i = 0; i < n; i++)
		if(ind != i)
		{
			nowx1 = max(nowx1 , x1[i]);
			nowx2 = min(nowx2 , x2[i]);

			nowy1 = max(nowy1 , y1[i]);
			nowy2 = min(nowy2 , y2[i]);
		}

	if(nowx1 <= nowx2 && nowy1 <= nowy2)
	{
		cout << nowx1 << " " << nowy1 << endl;
		exit(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	pair<int , int> mnx1 = {2e9 , 0} , mnx2 = {2e9 , 0};
	pair<int , int> mxx1 = {-2e9 , 0} , mxx2 = {-2e9 , 0};

	pair<int , int> mny1 = {2e9 , 0} , mny2 = {2e9 , 0};
	pair<int , int> mxy1 = {-2e9 , 0} , mxy2 = {-2e9 , 0};

	for(int i = 0; i < n; i++)
	{
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

		mnx1 = min(mnx1 , make_pair(x1[i] , i));
		mnx2 = min(mnx2 , make_pair(x2[i] , i));
		mny1 = min(mny1 , make_pair(y1[i] , i));
		mny2 = min(mny2 , make_pair(y2[i] , i));

		mxx1 = max(mxx1 , make_pair(x1[i] , i));
		mxx2 = max(mxx2 , make_pair(x2[i] , i));
		mxy1 = max(mxy1 , make_pair(y1[i] , i));
		mxy2 = max(mxy2 , make_pair(y2[i] , i));
	}

	f(mnx1.second);
	f(mnx2.second);
	f(mny1.second);
	f(mny2.second);

	f(mxx1.second);
	f(mxx2.second);
	f(mxy1.second);
	f(mxy2.second);
}