#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define endl '\n'

ll lcm(ll a, ll b) {	
	return a * b / __gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	srand(time(NULL));
	//ifstream cin("sum.in");
	//ofstream cout("sum.out");
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ll n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	ll both = lcm(a, b);
	cout << (n / a * p) + (n / b * q) - min((n / both) * p, (n / both) * q) << endl;
}