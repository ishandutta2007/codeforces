# include <bits/stdc++.h>

using namespace std;

const int xn = 5;
char a[xn][xn];

int main(){
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			cin >> a[i][j];
		}
	}
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			if (a[i][j] == '1'){
				int r = 0;
				if (i > 2){
					r += i-2;
				}
				else{
					r += 2-i;
				}
				if (j > 2){
					r += j-2;
				}
				else{
					r += 2-j;
				}
				cout << r;
				return 0;
			}
		}
	}
}