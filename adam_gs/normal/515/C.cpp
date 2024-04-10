#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int ile[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	rep(i, n) {
		ll x=s[i]-'0';
		ll p=1;
		for(ll i=2; i<=x; ++i) p*=i;
		for(ll j=2; j<10; ++j) {
			while(p%j==0) {
				p/=j;
				++ile[j];
			}
		}
	}
	while(ile[7]) {
		cout << 7;
		--ile[7];
		--ile[5];
		ile[3]-=2;
		ile[2]-=4;
	}
	while(ile[5]) {
		cout << 5;
		--ile[5];
		--ile[3];
		ile[2]-=3;
	}
	while(ile[3]) {
		cout << 3;
		--ile[3];
		--ile[2];
	}
	while(ile[2]) {
		cout << 2;
		--ile[2];
	}
	cout << '\n';
}