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
	int k = 1, n, u = 0,a[1111];
	memset(a, 0, sizeof(a));
	cin >> n;
	set < int > s[1111];
	s[0].insert(1);
	a[0] = 1;
	while(1){
		u = (u+k)%n;
		k = (k+1) % n;
		a[u] = 1;
		if(s[u].find(k)==s[u].end()) s[u].insert(k);
		else break;
	}
	for(int i = 0; i<n; i++)
		if(a[i] == 0){
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}