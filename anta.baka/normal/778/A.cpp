#include <bits/stdc++.h>

using namespace std;

string s, t;
int n, m, p[200000];

bool can(int w)
{
	if(!w) return true;
	vector<bool> in(n, true);
	for(int i = 0; i < w; i++) in[p[i]] = false;
	int i1 = 0;
	for(int i = 0; i < m; i++)
	{
		while(i1 < n && (!in[i1] || s[i1] != t[i])) i1++;
		if(i1 == n) return false;
		i1++;
	}
	return true;
}

int main()
{
	cin >> s >> t;
	n = s.length();
	m = t.length();
	for(int i = 0; i < n; i++) cin >> p[i], p[i]--;
	int bl = 0, br = n - m;
	while(bl < br)
	{
		int bm = (bl + br) >> 1;
		if(bl == bm) bm++;
		if(can(bm)) bl = bm;
		else br = bm - 1;
	}
	cout << bl;
}