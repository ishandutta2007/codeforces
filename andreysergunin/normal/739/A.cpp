#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

typedef long long ll;

using namespace std;	

const int ALPH = 26;


int main()
{
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");

	iostream::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int ans = n;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		ans = min(ans, b - a + 1);
	}

	cout << ans << endl;
	for (int i = 0; i < n; ++i)
		cout << i % ans << " ";
	cout << endl;

	return 0;
}