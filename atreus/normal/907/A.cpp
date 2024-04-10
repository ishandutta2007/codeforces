#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main (){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int q = -1, w = -1, e = -1;
	for (int i = c; i <= 2 * c; i++){
		if (i >= d and 2 * d >= i){
			e = i;
			break;
		}
	}
	for (int i = b; i <= 2 * b; i++){
		if (i >= d and 2 * d < i and i != e){
			w = i;
			break;
		}
	}
	for (int i = a; i <= 2 * a; i++){
		if (i >= d and 2 * d < i and i != e and i != w){
			q = i;
			break;
		}
	}
	if (q == -1 or w == -1 or e == -1)
		cout << -1 << endl;
	else
		cout << q << endl << w << endl << e << endl;
}