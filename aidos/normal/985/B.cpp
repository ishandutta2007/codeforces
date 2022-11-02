#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int m;
string s[2222];
int a[2222];
int main () {
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j<s[i].size(); j++) {
			a[j] += s[i][j] - '0';
		}
	}
	for(int i = 0; i < n; i++) {
		int cnt = 1;
		for(int j = 0; j<s[i].size(); j++) {
			a[j] -= s[i][j] - '0';
			cnt = min(cnt, a[j]);
		}
		if(cnt > 0) {
			cout << "YES\n";
			return 0;
		}
		for(int j = 0; j<s[i].size(); j++) {
			a[j] += s[i][j] - '0';
		}
	}
	cout << "NO\n";

    return 0;
}