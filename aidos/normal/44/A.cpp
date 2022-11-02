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
#define pss pair<string, string>
using namespace std;
int main () {
	int n;
	cin >> n;
	set < pss > s;
	for(int i = 0; i<n; i++){
		string u, t;
		cin >> u >> t;
		s.insert(mp(u, t));
	}
	cout << s.size();
	return 0;
}