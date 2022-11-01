# include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	long long n = a.size()/2;
	if (a.size()%2 == 0) n -= 1;
	bool f = 0;
	for (int i=1; i<a.size(); i++){
		if (a[i] == '1') f = 1;
	}
	if (f or a.size()%2 == 0) n += 1;
	cout << n;
	return 0;
}