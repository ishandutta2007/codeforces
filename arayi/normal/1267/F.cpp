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
const lli mod = 1e9 + 7;

int n, m, n1, n2;
vector <int> a, b;
int qan[N];
priority_queue <int, vector <int>, greater<int> > fp;
int main()
{
	fastio;
	cin >> n >> m >> n1 >> n2;
	if (n1 > m - 1 || n2 > n - 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n1; i++)
	{
		int x;
		cin >> x;
		qan[x]++;
		a.PB(x);
	}
	for (int i = n1; i < m - 1; i++)
	{
		a.PB(n);
		qan[n]++;
	}
	for (int i = 0; i < n2; i++)
	{
		int x;
		cin >> x;
		b.PB(x);
		qan[x]++;
	}
	for (int i = n2; i < n - 1; i++)
	{
		b.PB(n + m);
		qan[n + m]++;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 1; i <= n + m; i++)
	{
		if (!qan[i]) fp.push(i);
	}
	int mn = n + m;
	while (mn > 2)
	{
		mn--;
		if (fp.top() <= n)
		{
			//cout << b.size() << endl;
			qan[b.back()]--;
			cout << fp.top() << " " << b.back() << endl;
			fp.pop();
			if (qan[b.back()] == 0) fp.push(b.back());
			b.pop_back();
		}
		else
		{
			//cout << a.size() << endl;
			qan[a.back()]--;
			cout << fp.top() << " " << a.back() << endl;
			fp.pop();
			if (qan[a.back()] == 0) fp.push(a.back());
			a.pop_back();
		}
		
	}
	//cout << "SM";
	cout << fp.top() << " ";
	fp.pop();
	cout << fp.top() << endl;
	return 0;
}