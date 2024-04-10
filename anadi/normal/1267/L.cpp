#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 1007;

int n, l, k, cnt[26];
char ans[N][N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l >> k;
	string buf; cin >> buf;
	for(int i = 0; i < n * l; i++)
		cnt[buf[i] - 'a']++;
		
	int last = 0;
		
	for(int j = 0; j < l; j++)
	{
		int sm = 0;
		for(int t = 0; t < 26; t++)
		{
			int pv = sm;
			sm += cnt[t];
			if(sm >= (k - last))
			{
				int w = t - 1;
				for(int i = min(k - 1, last + pv) - 1; i >= last; i--)
				{
					while(cnt[w] == 0) w--;
					cnt[w]--;
					
					ans[i][j] = w + 'a';
				}
				
				w = t;
				for(int i = k - 1; i >= min(k - 1, last + pv); i--)
				{
					while(cnt[w] == 0) w--;
					cnt[w]--;
					
					ans[i][j] = w + 'a';
				}
				
				w = 25;
				for(int i = n - 1; i > k - 1; i--)
				{
					while(cnt[w] == 0) w--;
					cnt[w]--;
					ans[i][j] = w + 'a';
				}
				
				int fr = last;
				while(ans[last][j] < t + 'a')
					last++;
				for(int ii = last - 1; ii >= fr; ii--)
				{
					for(int o = l - 1; o > j; o--)
					{
						while(cnt[w] == 0) w--;
						cnt[w]--;
						ans[ii][o] = w + 'a';
					}
				}
				break;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		ans[i][l] = 0;
		if(i > 0)
		{
			string pv = ans[i - 1], nx = ans[i];
			assert(pv <= nx);
		}
		cout << ans[i] << "\n";
	}
	
	return 0;
}