#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5e5 + 3;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	bool ret = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ret |= x;
	}
	if (ret == 1)
		cout << "HARD\n";
	else
		cout << "EASY\n";
}