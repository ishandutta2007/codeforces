#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
const int maxn = 500 + 5;
const int inf = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, m;
		cin >> n >> m;
		if (n % m == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}