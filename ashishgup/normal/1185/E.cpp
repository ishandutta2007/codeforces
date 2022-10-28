#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2005;

int n, m;
char a[N][N], b[N][N];
map<char, int> lx, rx, ly, ry;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		lx.clear();
		rx.clear();
		ly.clear();
		ry.clear();
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				b[i][j] = '.';
				cin >> a[i][j];
				if(a[i][j] == '.')
					continue;
				if(lx.find(a[i][j]) == lx.end())
					lx[a[i][j]] = i;
				else
					lx[a[i][j]] = min(lx[a[i][j]], i);
				if(rx.find(a[i][j]) == rx.end())
					rx[a[i][j]] = i;
				else
					rx[a[i][j]] = max(rx[a[i][j]], i);
				if(ly.find(a[i][j]) == ly.end())
					ly[a[i][j]] = j;
				else
					ly[a[i][j]] = min(ly[a[i][j]], j);
				if(ry.find(a[i][j]) == ry.end())
					ry[a[i][j]] = j;
				else
					ry[a[i][j]] = max(ry[a[i][j]], j);
			}
		}
		if(!lx.size())
		{
			cout << "YES" << endl;
			cout << 0 << endl;
			continue;
		}
		bool check = 1;
		for(char ch = 'a'; ch <= 'z'; ch++)
		{
			if(lx.find(ch) == lx.end())
				continue;
			if(lx[ch] != rx[ch] && ly[ch] != ry[ch])
			{
				check = 0;
				break;
			}
			for(int i = lx[ch]; i <= rx[ch]; i++)
				for(int j = ly[ch]; j <= ry[ch]; j++)
					b[i][j] = ch;
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				check &= (a[i][j] == b[i][j]);
		if(!check)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			char last = lx.rbegin() -> first;
			int num = last - 'a' + 1;
			cout << num << endl;
			for(char ch = 'a'; ch <= last; ch++)
			{
				if(lx.find(ch) != lx.end())
					cout << lx[ch] << " " << ly[ch] << " " << rx[ch] << " " << ry[ch] << endl;
				else
				{
					char temp = ch;
					ch = last;
					cout << lx[ch] << " " << ly[ch] << " " << lx[ch] << " " << ly[ch] << endl;
					ch = temp;
				}
			}
		}
	}
	return 0;
}