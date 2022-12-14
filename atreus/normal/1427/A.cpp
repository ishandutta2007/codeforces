#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[60];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		if (sum == 0){
			cout << "NO\n";
			continue;
		}
		if (sum > 0)
			sort(a,a+n,greater<int>());
		else
			sort(a,a+n);
		cout << "YES\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << " \n"[i == n-1];
	}
}