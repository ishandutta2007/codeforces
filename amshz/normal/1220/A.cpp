# include <bits/stdc++.h>

using namespace std;

map <char,int> cnt;

int main(){
	int n;
	cin >> n;
	string a;
	cin >> a;
	for (int i=0; i<n; i++) cnt[a[i]]++;
	int r = 0, t = 0;
	r += cnt['n'];
	t = (n-r*3)/4;
	for (int i=0; i<r; i++) cout << 1 << ' ';
	for (int i=0; i<t; i++) cout << 0 << ' ';
}