#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, a[N], was[N], ans;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		ans += 1 - was[i];
		for(int j = 0; j < n; j++)
			if(a[j] % a[i] == 0)	
				was[j] = 1;
	}
	cout << ans;
	return 0;
}