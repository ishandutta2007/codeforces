#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define mp make_pair
#define lli long long int
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
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
using namespace std;
const int N = 1e5 + 20;
int a[] = { 42, 23, 16, 15, 8, 4 };
vector <int> pat;
int sm, sm1;
bool ka(int sm)
{
	for (int i = 0; i < 6; i++)
	{
		if (a[i] == sm)
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout << "? 1 2" << endl;
	cin >> sm;
	cout << "? 1 3" << endl;
	cin >> sm1;
	for (int i = 0; i < 6; i++)
	{
		if (sm % a[i] == 0 && sm1 % a[i] == 0)
		{
			if (a[i] != sm / a[i] && ka(sm / a[i]) && a[i] != sm1 / a[i] && ka(sm1 / a[i]))
				pat.push_back(a[i]), pat.push_back(sm / a[i]), pat.push_back(sm1 / a[i]);
		}
	}
	cout << "? 4 5" << endl;
	cin >> sm;
	cout << "? 4 6" << endl;
	cin >> sm1;
	for (int i = 0; i < 6; i++)
	{
		if (sm % a[i] == 0 && sm1 % a[i] == 0)
		{
			if (a[i] != sm / a[i] && ka(sm / a[i]) && a[i] != sm1 / a[i] && ka(sm1 / a[i]))
				pat.push_back(a[i]), pat.push_back(sm / a[i]), pat.push_back(sm1 / a[i]);
		}
	}
	cout << "! ";
	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i] << " ";
	}
	cout<<endl;
	return 0;
}