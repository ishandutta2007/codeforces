/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	char c[n];
	int l[n], r[n];
	bool b[n];
	for(int i = 0; i < n; i++){
		cin >> c[i];
		l[i] = 0;
		r[i] = 0;
		b[i] = false;
	}

	for(int i = 0; i < n; i++){
		if (c[i] == 'L'){
			l[i] = 1;
			for(int j = i - 1; j >= 0; j--){
				if (c[j] != '.')
					break;
				b[j] = true;
				l[j] = i - j;
			}
		}else if (c[i] == 'R'){
			r[i] = 1;
			for(int j = i + 1; j < n; j++){
				if (c[j] != '.')
					break;
				b[j] = true;
				r[j] = j - i;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if (l[i] == r[i])
			ans++;
	}
	cout << ans;

}