#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int gcd(int a, int b){return b ? gcd(b, a % b) : a;}

signed main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	int g = 0;
	for(int i = 0; i < n; i++)
		cin >> a[i], g = gcd(g, a[i]);
	int ans = 0;
	int palin = 1;
	for(int t = 1; t <= g; t++)
	{
		if(g % t)
			continue;
		int b[n];
		int nc = 0;
		for(int i = 0; i < n; i++)
			b[i] = a[i] / t,
			nc += b[i] % 2;
		if(nc > 2)
			continue;
		if(nc == 1 && t > ans)
			ans = t, palin = t;
		else if(nc == 0 && 2 * t > ans)
			ans = 2 * t, palin = t;
		
	}
	int sum = accumulate(a, a + n, 0);
	cout << ans << "\n";
	if(ans == 0)
	{
		for(int i = 0; i < n; i++)
			cout << string(a[i], 'a' + i);
		cout << "\n";
		return 0;
	}
	int b[n];
	for(int i = 0; i < n; i++)
		b[i] = a[i] / palin;
	int ss = accumulate(b, b + n, 0);
	string ANS(ss, 'a');
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		
		if(b[i] % 2 == 1)
		{
			ANS[ANS.size() / 2] = 'a' + i;
		}
		for(int k = 1; 2 * k <= b[i]; k++)
		{
			ANS[j] = ANS[ANS.size() - j - 1] = 'a' + i;
			j++;
		}
	}
	string tt = ANS;
	while(tt.size() < sum)
		tt += ANS;
	cout << tt << endl;
	
	
}