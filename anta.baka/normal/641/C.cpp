#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	list<int> l, r;
	for(int i = 1; i <= n; i++)
		if(i % 2)
			l.pb(i);
		else
			r.pb(i);
	bool ltor = true;
	int cnt = 0;
	for(int i = 0; i < q; i++) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int x;
			scanf("%d", &x);
			if(x < 0)
				x += n;
			cnt = (cnt + x/2) % (n/2);
			if(x%2) {
				if(ltor) {
					r.push_front(r.back());
					r.pop_back();
				} else {
					l.push_front(l.back());
					l.pop_back();
				}
				ltor = !ltor;
			}
		} else
			ltor = !ltor;
	}
	auto il = l.end(), ir = r.end();
	for(; cnt > 0; cnt--, il--, ir--) {}
	for(auto itl = il, itr = ir; itl != l.end(); itl++, itr++)
		if(ltor)
			printf("%d %d ", *itl, *itr);
		else
			printf("%d %d ", *itr, *itl);
	for(auto itl = l.begin(), itr = r.begin(); itl != il; itl++, itr++)
		if(ltor)
			printf("%d %d ", *itl, *itr);
		else
			printf("%d %d ", *itr, *itl);
}