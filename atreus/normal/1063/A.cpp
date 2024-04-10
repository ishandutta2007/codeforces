#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef complex<long double> cd;

int a[30];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		a[(int)(s[i] - 'a')] ++;
	for (int i = 0; i < 26; i++)
		while (a[i] --)
			cout << (char)(i + 'a');
	cout << endl;
}