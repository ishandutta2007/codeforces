#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n);
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		int mxm = a[n-1];
		if (mxm > sum-mxm or sum % 2 == 1)
			cout << "T\n";
		else
			cout << "HL\n";
	}
}