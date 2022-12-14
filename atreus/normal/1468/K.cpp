#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;

map<char,int> adjx = {{'L',-1},{'R',+1}};
map<char,int> adjy = {{'D',-1},{'U',+1}};

bool check(int n, string &s, int sx, int sy){
	if (sx == 0 and sy == 0)
		return false;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
		if (x + adjx[s[i]] != sx or y + adjy[s[i]] != sy)
			x += adjx[s[i]], y += adjy[s[i]];
	if (x == 0 and y == 0)
		return true;
	return false;
}

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int x = 0, y = 0;
	for (int i = 0; i < n; i++){
		x += adjx[s[i]], y += adjy[s[i]];
		if (check(n,s,x,y)){
			cout << x << " " << y << '\n';
			return;
		}
	}
	cout << "0 0\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}