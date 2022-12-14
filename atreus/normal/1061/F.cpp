#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int maxn = 5e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;

bool ask(int v, int u, int w){
	cout << "? " << v << " " << u << " " << w << endl;
	string s;
	cin >> s;
	return s == "Yes";
}

int get(vector<int> a, int v, int u, int k){
	if (k == 1)
		return v;
	if (k == a.size())
		return u;
	int t = rng() % (int)(a.size());
	vector<int> b, c;
	int w = a[t], cnt = 0;
	for (int i = 0; i < a.size(); i++){
		if (ask(v, a[i], w)){
			cnt ++;
			b.push_back(a[i]);
		}
		else
			c.push_back(a[i]);

		if (a[i] == w)
			c.push_back(a[i]);
	}
	if (cnt < k){
		k -= (cnt - 1);
		return get(c, w, u, k);
	}
	else
		return get(b, v, w, k); 
}

int dis(int v, int u){
	int ret = 0;
	for (int w = 1; w <= n; w++)
		ret += ask(v, w, u);
	return ret;
}

bool isleaf(int v){
	int u = 1;
	if (v == 1)
		u = 2; // diffrent from v
	for (int w = 1; w <= n; w++){
		if (w == v)
			continue;
		if (ask(u, v, w))
			return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin >> n >> k;
	int T = n;
	int H = 0;
	while (T >= 1){
		H ++;
		T /= k;
	}
	int v;
	while (true){
		v = rng() % n + 1;
		if (isleaf(v))
			break;
	}
	int u;
	while (true){
		u = rng() % n + 1;
		if (isleaf(u) and dis(v, u) == 2 * H - 1)
			break;
	}
	vector<int> a;
	for (int w = 1; w <= n; w++)
		if (ask(v, w, u))
			a.push_back(w);
	int root = get(a, v, u, H);
	cout << "! " << root << endl;
}