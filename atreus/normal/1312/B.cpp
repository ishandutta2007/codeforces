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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.rbegin(), a.rend());
		for (int i = 0; i < n; i++)
			cout << a[i] << " \n"[i == n-1];
	}
}