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
	string s, t, k;
	cin >> s >> t;
	int  r = s.size();
	for(int i = r-1; i>=0; i--)
		k+=s[i];
	if(k == t) cout << "YES";
	else cout << "NO";
	return 0;
}