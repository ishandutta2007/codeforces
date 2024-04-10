#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < n; i++)
#define fs first
#define sc second

using namespace std;

int const NMAX = 5010;
int n;
pair < pair <int, int>, int > q[NMAX];
vector <int> ans;
bool used[NMAX];

void check(int k)
{
	int now = 0;
	forn(i, n)
		if (i != k)
		{
			if (now > q[i].fs.fs) return;
			now = q[i].fs.sc;
		}
	ans.push_back(q[k].sc);
}

int main()
{
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	forn(i, n)
	{
		scanf("%d%d", &q[i].fs.fs, &q[i].fs.sc);
		q[i].sc = i + 1;
	}
	sort(q, q + n);

	ans.clear();
	forn(i, n)
		check(i);

	cout << ans.size() << endl;
	memset(used, 0, sizeof(used));
	forn(i, ans.size())
		used[ans[i] - 1] = true;

	forn(i, n)
		if (used[i]) cout << i + 1 << " ";

	return 0;
}