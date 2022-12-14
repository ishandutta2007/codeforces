#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0, k = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		if (i == 0 or a[i] * 2 <= a[0]){
			k += a[i];
			cnt ++;
		}
	}
	if (k <= sum / 2)
		return cout << 0 << endl, 0;
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		if (i == 0 or a[i] * 2 <= a[0])
			cout << i + 1 << " ";
	cout << endl;
}