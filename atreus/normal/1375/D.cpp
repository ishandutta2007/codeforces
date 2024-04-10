#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

int a[maxn], fen[maxn];
multiset<int> dels, adds;

void add(int idx, int val){
	if (val == 1){
		auto it = adds.find(idx);
		if (it != adds.end())
			adds.erase(it);
		dels.insert(idx);
	}
	else{
		dels.erase(dels.find(idx));
		auto it = dels.find(idx);
		if (it == dels.end())
			adds.insert(idx);
	}
}

int get(){
	return *(adds.begin());
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		dels.clear(), adds.clear();
		for (int i = 0; i <= n; i++)
			adds.insert(i);
		for (int i = 0; i < n; i++){
			cin >> a[i];
			add(a[i], +1);
		}
		vector<int> ops;
		while (true){
			int m = get();
			if (m < n){
				ops.push_back(m);
				add(a[m], -1);
				a[m] = m;
				add(a[m], +1);
				continue;
			}
			bool found = false;
			for (int i = n-1; i >= 0; i--){
				if (a[i] != i){
					ops.push_back(i);
					add(a[i], -1);
					a[i] = m;
					add(a[i], +1);
					found = true;
					break;
				}
			}
			if (!found)
				break;
		}
		cout << ops.size() << '\n';
		for (auto it : ops)
			cout << ++it << ' ';
		cout << '\n';
	}
}