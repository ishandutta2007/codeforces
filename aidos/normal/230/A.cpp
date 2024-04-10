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
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int main () {
	int s, n;
	vector < pii > v;
	cin >> s >> n;
	for(int i = 0; i<n; i++){
		int x, y;
		cin >> x >> y;
		v.pb(mp(x, y));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i<n; i++){
		if(s <= v[i].ff) {
			cout << "NO";
			return 0;
		}
		s+=v[i].sc;
	}
	cout << "YES";
    return 0;
}