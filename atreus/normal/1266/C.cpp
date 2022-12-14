#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 50;

int main(){
	ios_base::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	if (r == 1 and c == 1)
		return cout << "0\n", 0;
	int now = 2;
	if (r == 1 or c == 1){
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++)
				cout << now ++ << " ";
			cout << endl;
		}
		return 0;
	}
	for (int i = c + 1; i <= r + c; i++){
		for (int j = 1; j <= c; j++)
			cout << i * j << " ";
		cout << endl;
	}
}