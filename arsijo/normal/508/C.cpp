/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

void goHome(){
	cout << -1;
	//say goodbye
	exit(0);
}

const int d = 300;
int ar[500], a[2000], m, t, r, ans = 0;
bool b[2000];

void add(int pos){
	if(b[pos + d])
		goHome();
	b[pos + d] = true;
	for(int i = 1; i <= t; i++){
		a[pos + d + i]++;
	}
	ans++;
}

int main() {
	cin >> m >> t >> r;
	memset(b, 0, sizeof(b));
	memset(a, 0, sizeof(a));
	for(int i = 0; i < m; i++)
		cin >> ar[i];
	if(r > t)
		goHome();
	for(int i = 1; i <= r; i++){
		add(ar[0] - i);
	}
	for(int i = 1; i < m; i++){
		int c = r - a[ar[i] + d];
		if(r <= 0)
			continue;
		for(int j = 1; j <= c; j++){
			add(ar[i] - j);
		}
	}
	cout << ans;
}