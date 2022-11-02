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
	int n, d[111], l, r, s = 0;
	cin >> n >> l >> r;
	for(int i = 0; i<n; i++){
		if(i<l) continue;
		if(n-i-1>r) continue;
		s++;
	}
	cout << s;
    return 0;
}