#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long mn;
};

int N, M;
node seg[2000005];
pair<int, int> srt[500005];
long long val[500005];
long long bit[500005];
long long dp[500005];

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	seg[idx].mn = LLONG_MAX/4;
	if(l == r){ 
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int p, long long v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mn = v;
		return;
	}
	if(p <= (seg[idx].l+seg[idx].r)/2){
		upd(p, v, 2*idx);
	}
	else{
		upd(p, v, 2*idx+1);
	}
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mn;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

void upd(int n, long long v){
	if(!n){
		return;
	}
	while(n <= N){
		bit[n] += v;
		n += n&-n;
	}
}

long long query(int n){
	long long ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> srt[i].first;
		srt[i].second = i;
	}
	for(int i = 1; i<=N; i++){
		cin >> val[i];
		upd(i, val[i]);
	}
	sort(srt+1, srt+1+N);
	build(0, N, 1);
	upd(0, 0, 1);
	int lst = 0;
	int idx1 = 1, idx2 = 0;
	cin >> M;
	while(M--){
		int n;
		cin >> n;
		//cout << n << " " << query(N) << "\n";
		while(idx1 <= N && srt[idx1].first < n){
			idx1++;
		}
		while(idx1 <= N && srt[idx1].first == n){
			int i = srt[idx1].second;
			dp[i] = LLONG_MAX/4;
			dp[i] = min(dp[i], query(0, i-1, 1) + query(i-1));
			//cout << i << " " << dp[i] << " " << query(0, i-1, 1) << " " << query(i-1) << "\n";
			idx1++;
		}
		while(idx2 <= N && srt[idx2].first < n){
			if(srt[idx2].first == lst){
				//cout << "u: " << idx2 << endl;
				upd(srt[idx2].second, LLONG_MAX/4, 1);
			}
			else if(val[srt[idx2].second] > 0){
				//cout << "gone: " << srt[idx2].second << " " << val[srt[idx2].second] << "\n";
				upd(srt[idx2].second, -val[srt[idx2].second]);
			}
			idx2++;
		}
		int idx3 = idx2;
		while(idx3 <= N && srt[idx3].first == n){
			if(val[srt[idx3].second] > 0){
				//cout << "gone: " << srt[idx3].second << " " << val[srt[idx3].second] << "\n";
				upd(srt[idx3].second, -val[srt[idx3].second]);
			}
			if(srt[idx3].first == n){
				upd(srt[idx3].second, dp[srt[idx3].second] - query(srt[idx3].second), 1);
				//cout << "n: " << dp[srt[idx3].second] - query(srt[idx3].second) << endl;
			}
			idx3++;
		}
		lst = n;
	}
	//cout << LLONG_MAX/4 << endl;
	long long ans = seg[1].mn + query(N);
	if(ans >= LLONG_MAX/8){
		cout << "NO\n";
	}
	else{
		cout << "YES\n" << ans << "\n";
	}
}