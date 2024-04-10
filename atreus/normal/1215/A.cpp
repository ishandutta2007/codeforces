#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio (false);
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if (k1 > k2){
		swap(k1, k2);
		swap(a1, a2);
	}
	int m = a1 * (k1 - 1) + a2 * (k2 - 1);
	int mnm = max(0, n - m);
	int mxm = 0;
	if (a1 * k1 >= n)
		mxm = n / k1;
	else{
		mxm = a1;
		n -= a1 * k1;
		mxm += (n / k2);
	}
	cout << mnm << " " << mxm << endl;
}