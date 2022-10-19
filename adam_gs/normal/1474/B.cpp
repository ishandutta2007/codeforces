#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=1e5+7;
int prime[LIM];
vector<int>pr;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2; i<LIM; ++i) {
		if(prime[i]) continue;
		pr.pb(i);
		for(int j=2*i; j<LIM; j+=i) prime[j]=1;
	}
	int t;
	cin >> t;
	while(t--) {
		int d;
		cin >> d;
		int l=0, p;
		while(pr[l]<=d) ++l;
		p=pr[l];
		while(pr[l]-p<d) ++l;
		p*=pr[l];
		cout << p << '\n';
	}
}