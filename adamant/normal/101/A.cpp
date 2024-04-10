#include <bits/stdc++.h>

using namespace std;

int main() 
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	k = min(k, n);
	static int cnt[26];
	for(auto c: s)
		cnt[c - 'a']++;
	int p[26];
	iota(p, p + 26, 0);
	sort(p, p + 26, [&](int a, int b){return cnt[a] < cnt[b];});
	int sum = 0;
	int it = 0;
	while(it < 26 && sum + cnt[p[it]] <= k)
	{
		sum += cnt[p[it]];
		it++;
	}
	int ans = 0;
	for(int jt = it; jt < 26; jt++)
		ans += !!cnt[p[jt]];
	cout << ans << "\n";
	for(auto c: s)
	{
		bool ok = 1;
		for(int i = 0; i < it; i++)
			if(c - 'a' == p[i])
				ok = 0;
		if(ok)
			cout << c;
	}
}