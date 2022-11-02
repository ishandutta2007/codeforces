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
	int n, a[1111], sum = 0, ok = 1;
	cin >> n;
	a[0] = 0;
	for(int i = 1; i<=n; i++){
		char c;
		cin >> c;
		if(c!='4' && c!='7') ok = 0;
		sum += c-'0';
		a[i] = sum;		
	}
	if(ok && a[n]  == 2*a[n/2]) cout << "YES";
	else cout << "NO";

    return 0;
}