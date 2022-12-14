#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

set <int> s;
int a[5][10];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++)
			s.insert(a[i][j]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++){
			if (a[i][j] == 0)
				continue;
			for (int k = 0; k < n; k++){
				if (k == i)
					continue;
				for (int l = 0; l < 6; l++){
					int x = a[i][j];
					x *= 10;
					x += a[k][l];
					s.insert(x);
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 99; i++){
		if (s.find(i) != s.end())
			cnt ++;
		else
			break;
	}
	cout << cnt << endl;
}