#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int mn = *min_element(a+1, a+n+1);
		vector<int> b;
		for (int i = 1; i <= n; i++)
			if (a[i] % mn == 0)
				b.push_back(a[i]);
		sort(b.begin(), b.end());
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] % mn == 0)
				a[i] = b[cnt++];
		bool found = 0;
		for (int i = 1; i <= n-1; i++)
			if (a[i] > a[i+1])
				found = 1;
		if (found)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}