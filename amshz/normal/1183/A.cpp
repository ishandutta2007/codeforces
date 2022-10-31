# include <bits/stdc++.h>

using namespace std;

bool fn1(int n){
	int s = 0;
	while (n > 0){
		s += n%10;
		n /= 10;
	}
	return s%4 == 0;
}

int main(){
	int n;
	cin >> n;
	for (int i=n; i<=1111; i++){
		if (fn1(i)){
			cout << i << endl;
			return 0;
		}
	}
}