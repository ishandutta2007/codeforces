#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
	if(a > b) return gcd(b, a);
	if(a == 0) return b;
	return gcd(b%a, a);
}

int main(){
	ll la, ra, ta;
	cin >> la >> ra >> ta;
	ll lb, rb, tb;
	cin >> lb >> rb >> tb;
	ll g = gcd(ta, tb);
	ll d = (g+((lb-la)%g))%g;
	cout << max(0ll, max(min(rb - lb +1, ra - la + 1 - d), min(rb - lb + 1 - (g-d), ra - la  + 1))) << endl;
}