#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll answer = 0; 
		for (int i = 2; i <= n; i++)
			if (a[i] < a[i-1])
				answer += a[i-1]-a[i];
		cout << answer << '\n';
	}
}