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
	int n, ans = 0, sum = 0, a[111];
	cin >>n;
	for(int i = 0; i<n; i++){ cin >> a[i]; sum+=a[i];}
	for(int i = 0; i<n; i++){
		if((sum - a[i]) % 2 == 0) ans++;
	}
	cout << ans;
    return 0;
}