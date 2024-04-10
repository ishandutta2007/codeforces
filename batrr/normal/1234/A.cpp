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

int main()
{
	ll s, n, q, x;
	cin >> q;
	while(q--){
		s = 0;
		cin >> n;
		for(int i = 0; i < n; i++){	
			cin >> x;
			s += x;
		}
		cout << (s + n - 1) / n << endl;
	}
	return 0;
}