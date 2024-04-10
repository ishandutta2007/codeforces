#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int a[12][12];
int b[12][12];

bool check(int k[][12], int g[][12],int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (k[i][j] != g[i][j]) return false;
		}
	}
	return true;
}

bool vert(int f[][12], int n){
	int k[12][12];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			k[i][n - j - 1] = f[i][j];
		}
	}
	if (check(k, b, n)) return true;
	return false;
}

bool horiz(int f[][12], int n){
	int k[12][12];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			k[n-i-1][j] = f[i][j];
		}
	}
	if (check(k, b, n)) return true;
	return false;
}

bool vert_horiz(int f[][12], int n){
	int k[12][12];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			k[n - i - 1][n-j-1] = f[i][j];
		}
	}
	if (check(k, b, n)) return true;
	return false;
}

bool rotate(int f[][12],int n){
	int k[12][12];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			k[j][n - i - 1] = f[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			f[i][j] = k[i][j];
		}
	}
	if (check(k, b,n)) return true;
	if (vert(k, n)) return true;
	if (horiz(k, n)) return true;
	if (vert_horiz(k, n)) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			char k;
			cin >> k;
			if (k == 'X'){
				a[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			char k;
			cin >> k;
			if (k == 'X'){
				b[i][j] = 1;
			}
		}
	}
	if (rotate(a, n)) cout << "YES" << endl;
	else if (rotate(a, n)) cout << "YES" << endl;
	else if (rotate(a, n)) cout << "YES" << endl;
	else if (rotate(a, n)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}