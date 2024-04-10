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
	int n, a[10], d[5000], maxn = 0;
	cin >> n;
	for(int i = 0; i<3; i++)
		cin >> a[i];
	for(int i = 0; i<4200; i++)
		d[i] = 0;
	for(int i = 0; i<3; i++)
		d[a[i]] = 1;
	for(int i = 1; i<= n; i++){
		for(int j = 0; j<3; j++){
			if(a[j] < i && d[i-a[j]] != 0){
				d[i] = max(d[i-a[j]] + 1, d[i]);
			}
		}
	}
	cout << d[n];
    return 0;
}