#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 5;
 
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b, c;
		cin >> a >> b >> c;
		if (b > a)
			swap(a, b);
		if (c > a)
			swap(a, c);
		int sum = a + b + c;
		if (b + c >= a){
			cout << sum / 2 << '\n';
			continue;
		}
		cout << b + c << '\n';
	}
}