#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> L(M);
	for (int i = 0; i < M; i++)
	{
		string s(M, '0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> L[i];
	}
	string cur(M, '0');
	vector<int> idx(M);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int a, int b)
		 { return L[a] < L[b]; });
	int p = 0;
	for (int a : idx)
	{
		cur[a] = '1';
		cout << "? " << cur << endl;
		int ep = p + L[a], r = 0;
		cin >> r;
		if (ep == r)
			p = ep;
		else
			cur[a] = '0';
	}

	cout << "! " << p << endl;
}