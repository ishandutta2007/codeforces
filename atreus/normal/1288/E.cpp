#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

int a[maxn];
int last[maxn];
int mnm[maxn], mxm[maxn];
int fen[2][maxn];
int n, m;

int get(bool w, int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[w][idx];
	return ret;
}

int get(bool w, int l, int r){
	if (l > r)
		return 0;
	return get(w, r) - get(w, l - 1);
}

void add(bool w, int idx, int val){
	for (; idx <= max(n, m); idx += idx & -idx)
		fen[w][idx] += val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		mnm[i] = mxm[i] = i;
	for (int i = 1; i <= m; i++)
		mnm[a[i]] = 1;

	memset(last, -1, sizeof last);
	for (int i = 1; i <= m; i++){
		if (last[a[i]] == -1){
			int sum = get(0, a[i] + 1, n);
			add(0, a[i], +1);
			mxm[a[i]] = max(mxm[a[i]], sum + a[i]);
			add(1, i, +1);
		}
		else{
			int tmp = get(1, last[a[i]] + 1, i - 1);
			mxm[a[i]] = max(mxm[a[i]], tmp + 1);
			add(1, last[a[i]], -1);
			add(1, i, +1);
		}
		last[a[i]] = i;
	}

	for (int i = 1; i <= n; i++){
		if (last[i] == -1){
			int sum = get(0, i + 1, n);
			mxm[i] = max(mxm[i], sum + i);
		}
		else{
			int tmp = get(1, last[i] + 1, m);
			mxm[i] = max(mxm[i], tmp + 1);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << mnm[i] << " " << mxm[i] << endl;
}