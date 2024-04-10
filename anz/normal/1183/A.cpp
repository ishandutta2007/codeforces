#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

unordered_map<int, int> um;

bool check(int a)
{
	int sum = 0;
	sum += a / 1000;
	a %= 1000;
	sum += a / 100;
	a %= 100;
	sum += a / 10;
	a %= 10;
	sum += a;

	if (sum % 4 == 0) return true;
	else return false;
}

int main()
{
	int a; cin >> a;
	while (!check(a)) a++;
	cout << a;
}