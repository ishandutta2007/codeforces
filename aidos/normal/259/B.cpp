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
int a[4][4], mx = 0, k[5];
bool check(int z){
	if(2*z - k[0] - k[2] == a[0][2] + a[2][0]) return 1;
	return 0;
}
int main () {  
	for(int i = 0; i<3; i++){
		k[i] = 0;
		for(int j = 0; j<3; j++){
			cin >> a[i][j];
			k[i]+=a[i][j];
		}
		if(k[i]>mx) mx = k[i];
	}
	for(int z = mx+1; ; z++){
		if(check(z)){
			for(int i = 0; i<3; i++){
				for(int j = 0; j<3; j++){
					if(i == j) cout << z - k[i] << " ";
					else cout << a[i][j] << " ";
				}
				cout << endl;
			}
			return 0;
		}
	}
    return 0;
}