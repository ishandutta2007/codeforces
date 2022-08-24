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

int main() {
	ios_base::sync_with_stdio(0);
	srand(time(NULL));
	//ifstream cin("sum.in");
	//ofstream cout("sum.out");
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ll n, k;
	cin >> n >> k;
	ll p = (n / k) + 1;
	cout << p * k << endl;
}