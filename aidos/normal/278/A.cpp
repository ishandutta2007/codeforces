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
	int n, d[111], l, r, s = 0, t = 0;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> d[i];
	cin >> l >> r;
	l--, r--;
	if(l>r) swap(l, r);
	for(int i = l; i<r; i++){
		s+=d[i];
	}
	for(int i = 0; i<l; i++)
		t+=d[i];
	for(int i = r; i<n; i++)
		t+=d[i];
	cout << min(s, t);
    return 0;
}