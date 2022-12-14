#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << 2 * (n / 3) + (n % 3 != 0) << endl;
}