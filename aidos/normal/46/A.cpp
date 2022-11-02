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
	int n, k = 0;
	vector < int > v;
	cin >> n;
	for(int i = 1; i<n; i++){
		k = (k+i) % n;
		v.pb(k);
	}
	for(int i = 1; i<n; i++)
		cout << v[i-1]+1 << " " ;
	return 0;
}