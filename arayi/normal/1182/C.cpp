#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli cg(lli n) {
	return n ^ (n >> 1);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m, int a)
{
	if (x >= a && y >= a && x < n && y < m)
	{
		return true;
	}
	return false;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
using namespace std;
const int N = 1e5 + 30;
const lli mod = 1e9 + 7;
int n, pat, sm, i1, mxsm;
string ss[N];
vector <int> a[5][N];
int mx(int a, int b)
{
	if (a > b)return a;
	return b;
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ss[i];
		sm = 0;
		for (int j = 0; j < ss[i].length(); j++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (ss[i][j] == vow[x])
				{
					i1 = x;
					sm++;
					break;
				}
			}
		}
		mxsm = max(mxsm, sm);
		a[i1][sm].PB(i);
	}
	vector <pair <int, int>> er, ar;
	int f = -1, s = -1;
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j <= mxsm; j++)
		{
			for (int i1 = 0; i1 < a[i][j].size()/2; i1++)
			{
				er.PB(MP(a[i][j][2*i1], a[i][j][2*i1 + 1]));
			}
			
		}
	}
	for (int j = 0; j <= mxsm; j++)
	{
		f = -1, s = -1;
		for (int i = 0; i < 5; i++)
		{	
			if (a[i][j].size() % 2 == 1)
			{
				s = a[i][j][a[i][j].size() - 1];
				if (f == -1) f = s, s = -1;
			}
			if (f != -1 && s != -1) ar.PB(MP(f, s)), f = -1, s = -1;
		}
	}
	int ar1 = ar.size(), er1 = er.size();
	cout << min(ar1, er1) + mx((er1 - ar1) / 2, 0) << endl;
	int i;
	for (i = 0; i < min(ar1, er1); i++)
	{
		cout << ss[ar[i].fr] << " " << ss[er[i].fr] << endl;
		cout << ss[ar[i].sc] << " " << ss[er[i].sc] << endl;
	}
	for (; i < er1 - 1; i+=2)
	{
		cout << ss[er[i].fr] << " " << ss[er[i + 1].fr] << endl;
		cout << ss[er[i].sc] << " " << ss[er[i + 1].sc] << endl;
	}
	return 0;
}