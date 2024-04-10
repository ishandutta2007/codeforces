# include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	int n;
	cin >> n;
	cin >> a;
	int ans = 0;
	vector <char> c;
	for (int i=0; i<a.size(); i+=2){
		if (a[i] != a[i+1]) c.push_back(a[i]), c.push_back(a[i+1]);
		else {
			ans += 1;
			c.push_back('a'), c.push_back('b');
		}
	}
	cout << ans << endl;
	for (int i=0; i<c.size(); i++) cout << c[i];
}