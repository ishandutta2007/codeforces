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
	while(n%k == 0){
		l++;
		n/=k;
	}
	if(n == 1) cout << "YES\n" << l-1;
	else cout << "NO";
	return 0;
}