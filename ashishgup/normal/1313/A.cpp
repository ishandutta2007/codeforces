#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int A = a, B = b, C = c;
		vector<int> sa = {1, 0, 0, 1, 1, 0, 1};
		vector<int> sb = {0, 1, 0, 1, 0, 1, 1};
		vector<int> sc = {0, 0, 1, 0, 1, 1, 1};
		vector<int> idx = {0, 1, 2, 3, 4, 5, 6};
		int finAns = 0;
		do
		{
			int ans = 0;
			a = A, b = B, c = C;
			for(int i = 0; i < 7; i++)
			{
				if(sa[idx[i]] <= a && sb[idx[i]] <= b && sc[idx[i]] <= c)
				{
					ans++;
					a -= sa[idx[i]];
					b -= sb[idx[i]];
					c -= sc[idx[i]];
				}
			}
			finAns = max(finAns, ans);

		}while(next_permutation(idx.begin(), idx.end()));
		cout << finAns << endl;
	}
	return 0;
}