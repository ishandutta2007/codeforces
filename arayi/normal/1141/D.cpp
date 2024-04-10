#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 2e5 + 1;
int n, havqa[27], havqb[27], sma[N], ssa, smb[N], ssb, a[27][N], b[27][N];
string s, t;
vector <pair<int, int> > pat;
int main() {

	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '?')
		{
			sma[ssa] = i;
			ssa++;
		}
		else
		{
			a[s[i] - 'a'][havqa[s[i] - 'a']] = i;
			havqa[s[i] - 'a']++;
		}
		if (t[i] == '?')
		{
			smb[ssb] = i;
			ssb++;
		}
		else
		{
			b[t[i] - 'a'][havqb[t[i] - 'a']] = i;
			havqb[t[i] - 'a']++;
		}
	}
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < min(havqa[i], havqb[i]); j++)
		{
			pat.push_back(make_pair(a[i][j], b[i][j]));
		}
	}
	int i = 0;
	for (int j = 0; j < 27; j++)
	{
		for (int i1 = havqa[j]; i1 < havqb[j] && i < ssa; i1++)
		{
			pat.push_back(make_pair(sma[i], b[j][i1]));
			i++;
		}
	}
	int ib = 0;
	for (int j = 0; j < 27; j++)
	{
		for (int i1 = havqb[j]; i1 < havqa[j] && ib < ssb; i1++)
		{
			pat.push_back(make_pair(a[j][i1], smb[ib]));
			ib++;
		}
	}
	if (i < ssa)
	{
		for (int i1 = 0; i1 < ssa - i; i1++)
		{
			pat.push_back(make_pair(sma[i + i1], smb[ib + i1]));
		}
	}
	cout << pat.size() << endl;
	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i].fr + 1 << " " << pat[i].sc + 1<< endl;
	}
	return 0;
}