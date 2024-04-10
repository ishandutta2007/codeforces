#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

map<char,int> mp;
int a[4];
string s;

void get(int l, int r){
	int len = r - l + 1;
	if (len <= 0)
		return;
	if (len <= 3){
		cout << s[l];
		return;
	}
	a[0] = a[1] = a[2] = 0;
	a[mp[s[l]]] ++;
	a[mp[s[l+1]]] ++;
	a[mp[s[r]]] ++;
	a[mp[s[r-1]]] ++;
	char c;
	if (a[0] >= 2)
		c = 'a';
	else if (a[1] >= 2)
		c = 'b';
	else
		c = 'c';
	cout << c;
	get(l + 2, r - 2);
	cout << c;
}

int main(){
	ios_base::sync_with_stdio(false);
	mp['a'] = 0;
	mp['b'] = 1;
	mp['c'] = 2;
	cin >> s;
	int n = s.size();
	get(0, n - 1);
	cout << endl;
}