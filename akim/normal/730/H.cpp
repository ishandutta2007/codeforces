#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;      

int n, m, bad[N], x;
string res, p[N];
int main () {
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
	 	cin >> p[i];
	}
	for (int i = 1; i <= m; i++) {
	 	cin >> x;
	 	bad[x] = 1;
	 	if (i == 1) {
	 	 	res = p[x];
	 	 	continue;
	 	}
	 	if (res.size() != p[x].size()) {
	 	 	cout << "No";
	 	 	return 0;
	 	}
	 	for (int j = 0; j < res.size(); j++) 
	 		if (res[j] != '?' && res[j] != p[x][j])
	 			res[j] = '?';

	}
	for (int i = 1; i <= n; i++) {
	 	if (bad[i]) continue;
	 	if (res.size() != p[i].size()) continue;
	 	bool good = 0;
	 	for (int j = 0; j < res.size(); j++) {
	 	 	if (res[j] != '?' && res[j] != p[i][j]) good = 1;
	 	}
	 	if (!good) {
	 	 	cout << "No";
	 	 	return 0;
	 	}
	 	
	}
	cout << "Yes\n" << res;
	return 0;
return 0;
}