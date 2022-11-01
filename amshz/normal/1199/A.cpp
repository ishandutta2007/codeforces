# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 1e5+10;
int a[xn];
int b[xn];
 
int main(){
	int n ,x ,y;
	bool f;
	cin >> n >> x >> y;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i<n; i++){
		f = 1;
		for (int j=-x; j<=y; j++){
			if (i+j > 0 and i+j < n and a[i+j] < a[i]){
				f = 0;
				break;
			}
		}
		if (f){
			cout << i+1;
			return 0;
		}
	}
	return 0;
}