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
	int n, a[111111], k;
	cin >> n >> k;
	int x = n - n % 2;
	for(int i = 0; i<x; i++){
		if(i%2 == 0){
			a[2*i] = 2*i + 1;
			a[2*i+1] = 2*i + 2;
		}
		else {
			a[2*i] = 2*i+1;
			a[2*i+1] = 2*i + 2;
		}
	}
	for(int i = x; i<n; i++){
		a[2*i] = 2*i+1;
		a[2*i+1] = 2*i+2;
	}
	int z = k;
	for(int i = 0; i<z; i++){
		swap(a[2*i], a[2*i+1]);
	}
	for(int i = 0; i<n; i++)
		cout << a[2*i] << " " << a[2*i+1] << " ";
    return 0;
}