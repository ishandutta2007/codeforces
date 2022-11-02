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
	int n, k, l = 0;
	cin >> k >> n;
	cout << n+k-1 << endl;
	for(int i = 1; i<=k; i++){
		cout << i << " 1\n";
	}
	for(int i = 2; i<=n; i++)
		cout << "1 " << i << endl;;
	return 0;
}