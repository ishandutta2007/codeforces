#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

int a[maxn];

bool prime(int x){
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int> > edges;
	for (int i = 0; i < n; i++)
		edges.push_back({i, (i + 1) % n});
	for (int i = n; ; i++){
		if (prime(i))
			break;
		edges.push_back({i-n, i - n + n / 2});
	}
	cout << edges.size() << endl;
	for (auto it : edges)
		cout << 1 + it.first << " " << 1 + it.second << endl;
}