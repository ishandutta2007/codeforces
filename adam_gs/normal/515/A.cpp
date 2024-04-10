#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	a=abs(a);
	b=abs(b);
	a+=b;
	cout << (c>=a&&a%2==c%2?"Yes":"No") << '\n';
}