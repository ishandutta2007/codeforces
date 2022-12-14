#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

int d[10][10];
int a[10][10];

int main(){
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			cin >> a[i][j];
			a[i][j] %= 2;
			d[i][j] = 1;
		}
	}
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			if (a[i][j] == 1){
				d[i + 1][j] ^= 1;
				d[i][j + 1] ^= 1;
				d[i - 1][j] ^= 1;
				d[i][j - 1] ^= 1;
				d[i][j] ^= 1;
			}
		}
	}
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++)
			cout << d[i][j];
		cout << endl;
	}
}