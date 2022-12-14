#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 50 + 10;
const int mod = 998244353;

int a[maxn], cnt[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int x = *min_element(a + 1, a + n + 1);
	if (cnt[x] <= n / 2)
		cout << "Alice\n";
	else
		cout << "Bob\n";
}