#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 20;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		bool found = 0;
		for (int i = 30; i >= 0; i--){
			int x = 0, y = 0;
			for (int j = 1; j <= n; j++){
				if (a[j] & (1 << i))
					x ++;
				else
					y ++;
			}
			if (x % 2 == 0)
				continue;
			found = 1;
			if ((x % 4 == 1) or (y % 2 == 1))
				cout << "WIN\n";
			else
				cout << "LOSE\n";
			break;
		}
		if (!found){
			cout << "DRAW\n";
			continue;
		}
	}
}