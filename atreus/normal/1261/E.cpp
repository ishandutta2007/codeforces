#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 10;

int a[maxn];
bitset<maxn> bs[maxn];

void get_ans(int n){
	if (n == 0)
		return;
	bitset<maxn> me;
	me.reset();
	for (int i = 1; i <= n - 1; i++){
		if (a[i] > 1){
			a[i] --;
			bs[n + 1][i] = 1;
			me[i] = 1;
		}
	}
	bs[n + 1][n] = 1;
	a[n] --;
	get_ans(n - 1);
	for (int i = 1; i <= n; i++)
		if (a[n] > 0 and me != bs[i])
			bs[i][n] = 1, a[n] --;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	get_ans(n);
	cout << n + 1 << endl;
	for (int i = 1; i <= n + 1; i++){
		for (int j = 1; j <= n; j++)
			cout << bs[i][j];
		cout << '\n';
	}
}