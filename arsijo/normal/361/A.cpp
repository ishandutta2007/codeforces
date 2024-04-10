/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("a.in", "r", stdin); freopen("a.out","w",stdout);
	int n, k;
	cin >> n >> k;
	int ar[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ar[i][j] = 1;
		}
	}
	if (k > n){
		for(int i = 0; i < n; i++){
			ar[i][i] = k - n + 1;
		}
	}else if (k < n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - k; j++){
				ar[i][(i+j) % n] = 0;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << ar[i][j] << " ";
		cout << "\n";
	}
}