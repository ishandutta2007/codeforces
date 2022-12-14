#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, k;
		cin >> n >> k;
		int cnt = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i] == k)
				cnt ++;
			if (a[i] >= k)
				a[i] = 1;
			else
				a[i] = -1;
		}
		if (cnt == 0){
			cout << "no\n";
			continue;
		}
		if (cnt == n){
			cout << "yes\n";
			continue;
		}
		string answer = "no";
		int mnm = +1;
		for (int i = 0; i < n; i++){
			if (i > 0)
				a[i] += a[i-1];
			if (a[i] - mnm > 0){
				answer = "yes";
				break;
			}
			if (i > 0)
				mnm = min(mnm, a[i-1]);
			else
				mnm = min(mnm, 0);
		}
		cout << answer << '\n';
	}
}