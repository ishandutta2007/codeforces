# include <bits/stdc++.h>

using namespace std;

const int xn = 1e5+10;
string  a[xn];
int b[xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	bool f;
	for (int i=0; i<n; i++){
		f = 1;
		for (int j=i-1; j>=0; j--){
			if (a[i] == a[j]){
				cout << a[i] << b[j] << endl;
				b[i] += b[j]+1;
				f = 0;
				break;
			}
		}
		if (f){
			cout << "OK" << endl;
			b[i] += 1;
		}
	}
	return 0;
}