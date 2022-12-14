#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxn = 1e5 + 10;

int a[maxn], b[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		b[1] = a[1];
		for (int i = 2; i <= n; i++)
			b[i] = max(b[i-1], a[i]);
		int answer = 0;
		for (int i = 1; i <= n; i++){
			int diff = b[i] - a[i];
			answer = max(answer, (int)log2(diff) + 1);
		}
		cout << answer << '\n';
	}
}