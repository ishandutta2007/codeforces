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
	int n, k = 0, c[110], x, y, z = 0;
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> c[i];
		k+=c[i];
	}
	cin >> x >> y;
	z += c[0];
	k-=c[0];
	for(int i = 1; i<n; i++){
		if(z < x || z > y || k < x || k>y) {
			z+=c[i];
			k-=c[i];
			continue;
		}
		cout << i+1;
		return 0;
	}
	cout << 0;
    return 0;
}