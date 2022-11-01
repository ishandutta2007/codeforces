# include <bits/stdc++.h>

using namespace std;

int main(){
	int n ,m;
	cin >> n >> m;
	int n2 = m;
	int n3 = m-1;
	int mn = 0;
	int mx = 0;
	int t = 0;
	int q;
	
	if ((m == 0 and n > 1) or m > 9*n){
		cout << "-1 -1";
		return 0;
	}
	if (m == 0 and n == 1){
		cout << "0 0";
		return 0;
	}
	// maximum
	for (int i=0; i<n; i++){
		if (n-i-1 < m/9){
			q = 9;
		}
		else if (n-i-1 == m/9){
			q = m%9;
		}
		else{
			q = 0;
		}
		if (q == 0 and i == 0){
			q = 1;
			m -= 1;
		}
		cout << q;
	}
	cout << ' ';
	
	// minimum
	for (int i=0; i<n; i++){
		if (n2 >= 9){
			cout << 9;
			q = 9;
		}
		else{
			cout << n2;
			q = n2;
		}
		n2 -= q;
	}
}