#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
bool check(int i, int j){              
if(i<0 || i>2 || j<0 || j>2) return 0;
return 1;
}
int main () {   
int x, u[15][15], d[15][15];
for(int i=0; i<3; i++)
	for(int j=0; j<3; j++) {
		cin >> x;
		u[i][j] = x%2;
		d[i][j] = 1;
	}
for(int i=0; i<3; i++)
	for(int j=0; j<3; j++){
		if(u[i][j]){
			if(check(i+1, j)){
				d[i+1][j] = 1-d[i+1][j];			
			}
            if(check(i, j+1)){
				d[i][j+1] = 1-d[i][j+1];			
			}
			if(check(i, j-1)){
				d[i][j-1] = 1-d[i][j-1];
			}
            if(check(i-1, j)){
            	d[i-1][j] = 1-d[i-1][j];
            }
            d[i][j] = 1-d[i][j];
		}
	}
for(int i=0; i<3; i++){
	for(int j=0; j<3; j++)	cout << d[i][j];
	cout << endl;
}
return 0;
}