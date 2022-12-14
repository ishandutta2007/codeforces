#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
const int mod = 1e9 + 7;

int adj[maxn];
bool ok[maxn], mark[maxn];
int minnow = 1, maxnow;

int get_max(){
	while (mark[maxnow])
		maxnow--;
	return maxnow;
}

int get_min(){
	while (mark[minnow])
		minnow++;
	return minnow;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	minnow = 1, maxnow = 2*n;
	for (int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		adj[x] = y;
		adj[y] = x;
		ok[x] = 1;
	}
	int answer = 0;
	while (get_min() != 2*n+1){
		if (get_min() + adj[get_min()] == 2*n+1){
			mark[get_min()] = mark[adj[get_min()]] = 1;
			continue;
		}
		int MXA = get_min(), MNA = get_max();
		int MXB = adj[MNA], MNB = adj[MXA];
		if (MXB > MNB)
			return cout << -1 << endl, 0;
		mark[MXA] = mark[MNA] = mark[MXB] = mark[MNB] = 1;
		int tot = 2, cnt = ok[MXA] + ok[MNA];
		while (get_min() <= 2*n){
			int mnm = get_min();
			int mxm = get_max();
			if (mnm < MXA and mnm < MXB)
				return cout << -1 << endl, 0;
			if (mxm > MNA and mxm > MNB)
				return cout << -1 << endl, 0;
			if (mnm < MXB){
				if (MNB < adj[mnm] or adj[mnm] < MXB or MNA < mnm)
					return cout << -1 << endl, 0;
				tot ++;
				cnt += ok[mnm];
				MXA = mnm;
				MNB = adj[mnm];
				mark[mnm] = mark[adj[mnm]] = 1;
				continue;
			}
			if (mnm < MXA){
				if (MNA < adj[mnm] or adj[mnm] < MXA or MNB < mnm)
					return cout << -1 << endl, 0;
				tot ++;
				cnt += ok[adj[mnm]];
				MXB = mnm;
				MNA = adj[mnm];
				mark[mnm] = mark[adj[mnm]] = 1;
				continue;
			}
			if (mxm > MNB){
				if (adj[mxm] < MXB or MNB < adj[mxm] or mxm < MXA)
					return cout << -1 << endl, 0;
				tot ++;
				cnt += ok[mxm];
				MNA = mxm;
				MXB = adj[mxm];
				mark[mxm] = mark[adj[mxm]] = 1;
				continue;
			}
			if (mxm > MNA){
				if (adj[mxm] < MXA or MNA < adj[mxm] or mxm < MXB)
					return cout << -1 << endl, 0;
				tot ++;
				cnt += ok[adj[mxm]];
				MNB = mxm;
				MXA = adj[mxm];
				mark[mxm] = mark[adj[mxm]] = 1;
				continue;
			}
			break;
		}
		answer += min(cnt,tot-cnt);
	}
	cout << answer << endl;
}