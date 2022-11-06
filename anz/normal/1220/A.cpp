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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

unordered_map<char, int> um;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string str; cin >> str;

	for (int i = 0; i < n; i++)
		um[str[i]]++;

	int ans1 = min(um['o'], min(um['n'], um['e']));
	um['e'] -= ans1;
	um['o'] -= ans1;
	int ans2 = um['z'];
	for (int i = 0; i < ans1; i++) cout << "1 ";
	for (int i = 0; i < ans2; i++) cout << "0 ";
}