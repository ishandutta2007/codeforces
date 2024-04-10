#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define MAX 300001
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;

int main() {

	int v1, v2, t, d;
	cin >> v1 >> v2 >> t >> d;

	int ar[t];
	ar[0] = v1;
	ar[t - 1] = v2;
	for(int i = 1; i < t - 1; i++)
		ar[i] = ar[i - 1] + d;
	for(int i = t - 2; i > 0; i--)
		if(ar[i + 1] + d < ar[i])
			ar[i] = ar[i + 1] + d;
	ll sum = 0;
	for(int i = 0; i < t; i++)
		sum += ar[i];
	cout << sum;

}