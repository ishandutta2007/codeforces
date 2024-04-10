# include <bits/stdc++.h>

using namespace std;

const int xn = 1e6+10;
int b[xn];

int main(){
	string a;
	cin >> a;
	int t = 0;
	stack <int> c;
	int f = 0;
	for (int i=0; i<a.size(); i++){
		if (f > 0 and a[i] == ')'){
			t += 2;
			f -= 1;
		}
		if (a[i] == '('){
			f += 1;
		}
	}
	cout << t << endl;
	return 0;
}