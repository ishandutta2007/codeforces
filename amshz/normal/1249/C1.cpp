# include <bits/stdc++.h>

using namespace std;

const int xn = 1e4+10;
int a[xn];

bool fn1(int n){
	while (n > 0){
		if (n%3 == 2) return false;
		n/=3;
	}
	return true;
}

int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		int i = n;
		while (true){
			if (fn1(i)){
				//cout << "ans : ";
				cout << i << endl;
				break;
			}
			i++;
		}
	}
}