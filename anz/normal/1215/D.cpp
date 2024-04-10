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

int n;
string s;

ll leftSum, rightSum;
int leftHole, rightHole;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n / 2; i++)
	{
		if (s[i] == '?') leftHole++;
		else leftSum += s[i] - '0';
	}
	for (int i = n / 2; i < n; i++)
	{
		if (s[i] == '?') rightHole++;
		else rightSum += s[i] - '0';
	}

	if (leftHole > rightHole)
	{
		swap(leftHole, rightHole);
		swap(leftSum, rightSum);
	}

	// now leftHole <= rightHole`

	leftSum -= rightSum;
	rightSum = 0;
	rightHole -= leftHole;
	leftHole = 0;

	if (leftSum == 9 * (rightHole / 2))
		cout << "Bicarp";
	else
		cout << "Monocarp";
}