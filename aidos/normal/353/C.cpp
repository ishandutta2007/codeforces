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
	int n, x[110111], a[110111], b[110111], mm = 0;
	x[0] = 0;
	a[0] = 0;
	cin >> n;
	for(int i = 1; i<=n; i++)
		cin >> b[i];
	string s;
	cin >> s;
	for(int i = 1; i<=n; i++){
		x[i] = x[i-1] + (s[i-1] - '0' ) * b[i];
		a[i] = a[i-1] + b[i];
	}
	mm = x[n];
	for(int i = n; i>0; i--){
		if(s[i-1] == '1'){
			mm = max(a[i-1] + x[n] - x[i], mm);
		}
	}
	cout << mm;
    return 0;
}