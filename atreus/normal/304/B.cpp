#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int y){
	if (y % 400 == 0)
		return true;
	if (y % 100 == 0)
		return false;
	if (y % 4 == 0)
		return true;
	return false;
}

int get(int y, int m, int d){
	int cnt = 0;
	for (int i = 1; i < y; i++){
		cnt += 365 + isleap(i);
	}
	if (isleap(y))
		a[2] = 29;
	else
		a[2] = 28;
	for (int i = 1; i < m; i++)
		cnt += a[i];
	cnt += d;
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int y = stoi(s.substr(0, 4)), m = stoi(s.substr(5, 2)), d = stoi(s.substr(8, 2));
	int Y = stoi(t.substr(0, 4)), M = stoi(t.substr(5, 2)), D = stoi(t.substr(8, 2));
	cout << abs(get(Y, M, D) - get(y, m, d)) << endl;
}