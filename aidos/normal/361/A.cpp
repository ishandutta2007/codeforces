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
	int n, k, a[111][111];
	cin >> n >> k;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(i == j) cout << k << " ";
			else cout << "0 ";
		}
		cout << endl;
	}
    return 0;
}