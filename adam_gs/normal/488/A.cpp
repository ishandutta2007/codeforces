#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
bool dobrze(int x) {
	x=abs(x);
	while(x) {
		if(x%10==8) return true;
		x/=10;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ans=1;
	while(!dobrze(n+ans)) ++ans;
	cout << ans << '\n';
}