#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;
const int mod = 1e9 + 7;

int c[maxn], mark[maxn], ans[maxn];

int ask(vector<int> &Q){
	if (Q.empty())
		return 0;
	cout << "? " << Q.size() << " ";
	for (auto it : Q)
		cout << it << " ";
	cout << endl;
	int x;
	cin >> x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			mark[i] = 0;
		for (int i = 1; i <= k; i++){
			cin >> c[i];
			for (int j = 1; j <= c[i]; j++){
				int x;
				cin >> x;
				mark[x] = i;
			}
		}
		int mxm = 0;
		vector<int> Q(n);
		for (int i = 0; i < n; i++)
			Q[i] = i+1;
		mxm = ask(Q);
		int idx = 0;
		for (int i = 0; i < 10; i++){
			vector<int> Q;
			idx ^= (1 << i);
			for (int j = 1; j <= n; j++)
				if ((j & idx) == idx)
					Q.push_back(j);
			int t = ask(Q);
			if (t != mxm)
				idx ^= (1 << i);
		}
		for (int i = 1; i <= k; i++)
			ans[i] = mxm;
		if (mark[idx] != 0){
			vector<int> Q;
			for (int i = 1; i <= n; i++)
				if (mark[i] != mark[idx])
					Q.push_back(i);
			ans[mark[idx]] = ask(Q);
		}
		cout << "! ";
		for (int i = 1; i <= k; i++)
			cout << ans[i] << " ";
		cout << endl;
		string report;
		cin >> report;
		assert(report == "Correct");
	}
}