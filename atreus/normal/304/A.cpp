#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	for (int a = 1; a <= n; a++){
		for (int b = a; b <= n; b++){
			int s = a*a + b*b;
			int t = sqrt(s);
			if (t * t == s and t <= n)
				cnt ++;
		}
	}
	cout << cnt << endl;
}