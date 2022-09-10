#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 50;

LL cnt[N], choose[N][N];

void solve()
{
	LL x, d = 2; 
	cin >> x;
	
	for(int i = 0; i < N; i++)
		cnt[i] = 0;
	
	while(x > 0)
	{
		cnt[x % d]++;
		x /= d;
		d++;
	}
	
	LL l = d - 2, s = 0, ans = 1;
	for(int i = N - 1; i >= 0; i--)
	{
		if(!cnt[i]) continue;
		
		LL k = l - max(i, 1) - s + 1;
		//cerr << "! " << i << " " << cnt[i] << " " << k << " " << l << " " << i << " " << s << "\n";
		ans *= choose[k][cnt[i]];
		s += cnt[i];
	}
	//cerr << ans << "\n";
	
	if(cnt[0] > 0)
	{
		l = d - 3, s = 0;
		LL ans2 = 1;
		cnt[0]--;
	
		for(int i = N - 1; i >= 0; i--)
		{
			if(!cnt[i]) continue;
		
			LL k = l - max(i, 1) - s + 1;
			if(0 <= cnt[i] && cnt[i] <= k)
				ans2 *= choose[k][cnt[i]];
			else
				ans2 = 0;
			s += cnt[i];
		}
		
		ans -= ans2;
		//cerr << ans2 << "\n";
	}
	
	cout << ans - 1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	for(int i = 0; i < N; i++)
	{
		choose[i][0] = choose[i][i] = 1;
		for(int j = 1; j < i; j++)
			choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
	}

	int t; cin >> t;
	while(t--)
	{
		solve();
	}	
		
	return 0;
}

/*
! 1 1 1 1 1 0
1
0
! 2 1 2 3 2 0
! 1 2 2 3 1 1
2
1
! 4 1 5 8 4 0
! 3 2 5 8 3 1
! 2 1 4 8 2 3
! 0 4 5 8 0 4
1000
288
711
*/