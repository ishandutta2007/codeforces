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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, a[1111], m, k;
	cin >> n;
	memset(a, 0, sizeof(a));
	a[n] = 1;
	for(int i=0; i<3; i++){
		cin >> m >> k;
		swap(a[m], a[k]);
	}
	for(int i = 0; i<10; i++){
		if(a[i] != 0){
			cout << i;
			return 0;
		}
	}
	return 0;
}