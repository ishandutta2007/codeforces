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
	int n;
	cin >> n;
	if(n > 0) cout << n;
	else {
		int k=-n, a[5];
		a[0] = k % 10;
		k/=10;
		a[1] = k % 10;
		k/=10;
		k*=10;
		k+=min(a[0], a[1]);
		cout <<-k;
	}
    return 0;
}