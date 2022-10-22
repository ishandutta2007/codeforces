#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

vector<ll> calc(int n, string pattern, char plusOne, char minusOne)
{
	vector<ll> answer(n, INF);
	
	int pSize = pattern.size();
	
	int minX = 0, maxX = 0;
	int x = 0;
	for (int i = 0; i < pSize; i++)
	{
		if (pattern[i] == plusOne)
			x++;
		if (pattern[i] == minusOne)
			x--;
		
		minX = min(x, minX);
		maxX = max(x, maxX);
		
		if (x > 0 && n - x >= 0)
			answer[n - x] = min(answer[n - x], (ll)i + 1);
		if (x < 0 && -x - 1 < n)
			answer[-x - 1] = min(answer[-x - 1], (ll)i + 1);
	}
	
	if (x > 0)
	{
		for (int i = n - 1; i >= 0; i--)
			if (answer[i] == INF)
				answer[i] = answer[i + x] + pSize;
	}
	else if (x < 0)
	{
		for (int i = 0; i < n; i++)
			if (answer[i] == INF)
				answer[i] = answer[i + x] + pSize;
	}
	
	return answer;
}

const ll MOD = 1e9 + 7;

void add(ll& x, ll y)
{
	x += y;
	x %= MOD;
}

ll countHeq(vector<ll>& x, ll y)
{
	return x.end() - lower_bound(x.begin(), x.end(), y);
}

int main()
{
	int n, h, w;
	string pattern;
	cin >> n >> h >> w >> pattern;
	
	vector<ll> a = calc(w, pattern, 'R', 'L');
	vector<ll> b = calc(h, pattern, 'D', 'U');
	
#if 0
	for (int i = 0; i < w; i++)
		printf("%lld ", a[i]);
	printf("\n");
	
	for (int i = 0; i < h; i++)
		printf("%lld ", b[i]);
	printf("\n");
#endif
	
#define all(v) (v).begin(), (v).end()
	
	sort(all(a));
	sort(all(b));
	
	if (a.back() == INF && b.back() == INF)
	{
		printf("-1\n");
		return 0;
	}
	
	ll answer = 0;
	
	for (int i = 0; i < w; i++)
	{
		// count all >=
		add(answer, (countHeq(b, a[i])) * (ll)a[i]);
	}
	
	for (int i = 0; i < h; i++)
	{
		// count all >
		add(answer, (countHeq(a, b[i] + 1)) * (ll)b[i]);
	}
	
	cout << answer << endl;
	
	return 0;
}