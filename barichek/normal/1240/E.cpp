#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll = long long;
 
const int nax = 1e6 + 5;
int cnt[nax];
int pref_cnt[nax];
pair<int,int> two_last[nax];
 
int main() {
	int n;
	scanf("%d", &n);
	vector<int> in(n);
	int big = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &in[i]);
		++cnt[in[i]];
		big = max(big, in[i]);
	}
	for(int i = 1; i < nax; ++i) {
		pref_cnt[i] = pref_cnt[i-1] + cnt[i];
		two_last[i] = two_last[i-1];
		for(int rep = 0; rep < min(2, cnt[i]); ++rep) {
			two_last[i].second = two_last[i].first;
			two_last[i].first = i;
		}
	}
	long long answer = 0;
	vector<int> order;
	for(int y = 2; y <= big; ++y) {
		order.push_back(y);
	}
	for(int y : order) {
		long long cnt_y = 0;
		vector<int> candidates;
		for(int tmp : {two_last[y-1].second, two_last[y-1].first}) {
			if(tmp >= 2) {
				candidates.push_back(tmp);
			}
		}
		for(int times = 1; y * times <= big; ++times) {
			int L = y * times;
			int R = min(big, y * (times + 1) - 1);
			// two_last[R]
			cnt_y += (ll) times * (pref_cnt[R] - pref_cnt[L-1]);
			if(two_last[R].second >= L) {
				candidates.push_back(two_last[R].second);
			}
			if(two_last[R].first >= L) {
				candidates.push_back(two_last[R].first);
			}
		}
		debug() << imie(y) imie(cnt_y) imie(candidates);
		long long low = 2, high = cnt_y; // interval for x
		high = min(high, (ll) big);
		bool started = false;
		while(low <= high) {
			ll x = (low + high) / 2;
			if(!started) {
				x = answer / y;
				while(x * y <= answer) {
					++x;
				}
				if(x > high) {
					low = high = 0;
					break;
				}
				if(x < 2) {
					x = 2;
				}
			}
			if(!started) {
				assert(x * y > answer);
			}
			ll spare = cnt_y - x;
			bool found = false;
			ll best_one = spare + 1;
			for(int a : candidates) {
				if(a < x) {
					continue;
				}
				debug() << imie(y) imie(x) imie(a) imie(spare);
				if(a >= 2 * x && spare >= a / y - (a - 2 * x) / y) {
					found = true;
					break;
				}
				int lost_y = a / y - (a - x) / y;
				if(best_one + lost_y <= spare) {
					found = true;
					break;
				}
				best_one = min(best_one, (ll) lost_y);
			}
			if(found) {
				low = x + 1;
				answer = max(answer, x * y);
			}
			else {
				high = x - 1;
				if(!started) {
					low = high = 0;
					break;
				}
			}
			started = true;
		}
		
	}
	printf("%lld\n", answer);
}