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
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e6 + 30;
const ld mod = 1e6;

int q;
string a, b;
int pr[200], pr1[200];
bool stg()
{
	for (int i = 0; i < 200; i++)
	{
		if (pr[i] != pr1[i]) return false;
	}
	return true;
}
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		memset(pr, 0, sizeof(pr));
		memset(pr1, 0, sizeof(pr1));
		int k = a.length();
		for (int i = 0; i < a.length(); i++)
		{
			pr1[a[i]]++;
		}
		for (int i = 0; i < min((int)b.length(), k); i++)
		{
			pr[b[i]]++;
		}
		if (stg())
		{
			cout << "YES\n";
			continue;
		}
		bool bl = true;
		for (int i = k; i < b.length(); i++)
		{
			pr[b[i]]++;
			pr[b[i - k]]--;
			if (stg())
			{
				cout << "YES\n";
				bl = false;
				break;
			}
		}
		if (bl) cout << "NO\n";
	}
	return 0;
}