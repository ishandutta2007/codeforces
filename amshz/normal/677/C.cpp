# include <bits/stdc++.h>

using namespace std;

int f2(char b){
	int n;
	n = b;
	if (n >= 48 and n <= 57){
		return n-48;
	}
	if (n >= 65 and n <= 65+27){
		return n-55;
	}
	if (n >= 97 and n <= 97+27){
		return n-61;
	}
	if (b == '-'){
		return 62;
	}
	if (b == '_'){
		return 63;
	}
}
int f3(int n){
	vector <int> f;
	while (n > 1){
		if (n%2 == 0){
			f.push_back(0);
		}
		else{
			f.push_back(1);
		}
		n /= 2;
	}
	f.push_back(n);
	int t = 0;
	for (int i=0; i<f.size(); i++){
		if (f[i] == 1){
			t += 1;
		}
	}
	t = 6-t;
	return t;
}
int f1(string a){
	int t = 0;
	int b;
	for (int i=0; i<a.size(); i++){
		b = f2(a[i]);
		t += f3(b);
	}
	long long int s = 1;
	long long int q = 1e9+7;
	for (int i=0; i<t; i++){
		s *= 3;
		s = s%q;
	}
	return s;
}
int main(){
	string a;
	cin >> a;
	cout << (f1(a));
}