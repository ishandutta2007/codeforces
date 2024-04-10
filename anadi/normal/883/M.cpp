#include <bits/stdc++.h>

using namespace std;

int X1, Y1;
int X2, Y2;

int main(){
	cin >> X1 >> Y1 >> X2 >> Y2;
	int res = 2 * abs(X1 - X2) + 2 * abs(Y1 - Y2) + 4 + 2 * (X1 == X2) + 2 * (Y1 == Y2);
	cout << res;
	return 0;
}