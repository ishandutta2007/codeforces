#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll base = 13;

int t[maxn];

int smax(multiset<int> &s){
	auto it = s.end();
	it --;
	return *it;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	while (b < a or c < b){
		if (b < a)
			swap(b, a);
		if (c < b)
			swap(c, b);
	}
	multiset<int> s;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		s.insert(t);
	}
	int ans = 0;
	while (!s.empty()){
		int m = smax(s);
		if (m > a + b + c)
			return cout << -1 << endl, 0;
		if (m <= c)
			break;
		if (m <= a + b){
			ans ++;
			s.erase(s.find(m));
			auto it = s.upper_bound(c);
			if (it != s.begin()){
				it --;
				s.erase(it);
			}
		}
		else if (m <= a + c){
			ans ++;
			s.erase(s.find(m));
			auto it = s.upper_bound(b);
			if (it != s.begin()){
				it --;
				s.erase(it);
			}
		}
		else if (m <= b + c){
			ans ++;
			s.erase(s.find(m));
			auto it = s.upper_bound(a);
			if (it != s.begin()){
				it --;
				s.erase(it);
			}
		}
		else{
			ans ++;
			s.erase(s.find(m));
		}
	}
	if (s.empty())
		return cout << ans << endl, 0;
	int l = 0, r = 0;
	for (auto it : s)
		t[r ++] = it;
	r --;
	int lo = 0, hi = r + 2;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		int L = 0, R = r - mid;
		int cnta = mid, cntb = mid;
		for (int i = R; i >= 0; i--, R --){
			if (t[i] > b){
				if (a + b >= t[i] and cntb > 0 and cnta > 0){
					cntb --, cnta --;
					continue;
				}
				break;
			}
			if (cntb > 0){
				cntb --;
				continue;
			}
			if (t[i] > a or cnta == 0)
				break;
			cnta --;
		}
		if (R < L)
			hi = mid;
		else
			lo = mid;
	}
	cout << ans + hi << endl;
}