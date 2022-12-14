#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;

const int maxn = 2e5 + 10;

pair<int,int> a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].first;
	for (int i = 0; i < n; i++)
		cin >> a[i].second;
	sort(a, a + n, [](pair<int,int> s, pair<int,int> t){
		if (s.first != t.first)
			return s < t;
		return s > t;
	});
	ll sum = 0;
	int t = 0;
	multiset<int> s;
	ll now = 0;
	for (int i = 0; i < n; i++){
		while (t != a[i].first){
			if (!s.empty()){
				auto it = s.end();
				it --;
				now -= *it;
				s.erase(it);
				sum += now;
				t ++;
			}
			else
				t = a[i].first;
		}
		now += a[i].second;
		s.insert(a[i].second);
		while (i < n - 1 and a[i + 1].first == t){
			i ++;
			s.insert(a[i].second);
			now += a[i].second;
		}
		auto it = s.end();
		it --;
		now -= *it;
		s.erase(it);
		sum += now;
		t ++;
	}
	while (!s.empty()){
		auto it = s.end();
		it --;
		now -= *it;
		s.erase(it);
		sum += now;
		t ++;
	}
	cout << sum << '\n';
}