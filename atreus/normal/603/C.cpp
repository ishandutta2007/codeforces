/**
 *    author:  Atrues
 *    created: 24.01.2019 16:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k;

int pre[] = {0, 1, 0, 1, 2};

int grundy(int x){
	if (k == 0){
		if (x == 1)
			return 1;
		if (x == 2)
			return 2;
		return (x % 2) ^ 1;
	}
	else{
		if (x < 5)
			return pre[x];
		if (x % 2 == 1)
			return 0;
		return grundy(x / 2) == 1 ? 2 : 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> k;
	k %= 2;
	int answer = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		answer ^= grundy(x);
	}
	if (answer == 0)
		cout << "Nicky\n";
	else
		cout << "Kevin\n";
}