//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif

void solve() {
	int n;
	long long x;
	scanf("%d%lld", &n, &x);
	vector<int> v(n);
	map<long long, int> mp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		++mp[v[i]];
	}
	sort(v.begin(), v.end());
	int odp = 0;
	for (int i : v) {
		while (mp[i]) {
			if (mp[x * i]) {
				--mp[i];
				--mp[x * i];
			}
			else {
				--mp[i];
				++odp;
			}
		}
	}
	printf("%d\n", odp);
}

int main() {
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}