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
	ll q;
	cin >> q;
	while(q--){
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		//x * n + y == s    x <= a y <= b
		if(a * n + b >= s && b >= s % n)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}