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
int get(int a, int b, int c){
	if(a) return a;
	if(b) return b;
	return c;
}
int main () {  
	int a[111000], n, k, l, m, x;
	memset (a, 0, sizeof(a));
	cin >> n >> x;
	for(int i = 0; i<x; i++){
		cin >> k>>l>>m;
		int z = get(a[k], a[l], a[m]);
		if(z){
			for(int j=1; j<4; j++){
				if(z!=j){
					if(!a[k]) a[k] = j;
					else if(!a[l]) a[l] = j;
					else if(!a[m]) a[m] = j;
				}
			}
		}
		else {
			a[k] = 1;
			a[l] = 2;
			a[m] = 3;
		}
	}	
	for(int i = 0; i<n; i++)
		if(a[i+1]) cout << a[i+1] << " ";
		else cout << "1 ";
    return 0;
}