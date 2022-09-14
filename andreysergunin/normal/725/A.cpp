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
#include <string.h>
#include <assert.h>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = 0;
	while (k < n && s[k] == '<')
		++k;

	int l = n - 1;
	while (l >= 0 && s[l] == '>')
		--l;

	cout << k + n - 1 - l << endl;

	return 0;
}