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
ll a[200200], l = 0, k = 0, n,t = 1;
int main () {
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	cin >> l;
	for(int i = 0; i<l; i++){
		cin >> k >> t;
		cout << max(a[0], a[k-1]) << "\n";
		a[0] = max(a[0], a[k-1]) + t;
	}
    return 0;
}