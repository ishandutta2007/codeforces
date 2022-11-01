# include <bits/stdc++.h>

using namespace std;

int main(){
	string a ,b ,c;
	cin >> a >> b >> c;
	if (a == b and a == c){
		cout << 0;
		return 0;
	}
	int t = 0;
	if (a[1] == b[1] and a[1] == c[1]){
		if (a[0]-b[0] == -1 or a[0]-b[0] == 1){
			t += 1;
		}
		if (b[0]-c[0] == -1 or b[0]-c[0] == 1){
			t += 1;
		}
		if (a[0]-c[0] == -1 or a[0]-c[0] == 1){
			t += 1;
		}
		if (t == 2){
			if ((a[0]-b[0] == 2 or a[0]-b[0] == -2) or (a[0]-c[0] == 2 or a[0]-c[0] == -2) or ((c[0]-b[0] == 2 or c[0]-b[0] == -2))){
				cout << 0;
				return 0;
			}
		}
	}
	if ((a == b) or (a == c) or (b == c)){
		cout << 1;
		return 0;
	}
	if ((a[1] == b[1] and (a[0]-b[0] == -2 or a[0]-b[0] == -1 or a[0]-b[0] == 1 or a[0]-b[0] == 2)) or (a[1] == c[1] and (a[0]-c[0] == -2 or a[0]-c[0] == -1 or a[0]-c[0] == 1 or a[0]-c[0] == 2) or (c[1] == b[1] and (c[0]-b[0] == -2 or c[0]-b[0] == -1 or c[0]-b[0] == 1 or c[0]-b[0] == 2)))){
		cout << 1;
		return 0;
	}
	cout << 2;
	return 0;
}