
// Problem : E. Alex and Complicated Task
// Contest : Codeforces - Codeforces Round #267 (Div. 2)
// URL : https://codeforces.com/contest/467/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	int mx;
};

Node seg[2000005];
int N;
int arr[500005];
int mn[500005];
pair<int, int> bst[500005];
vector<int> pos[500005];
vector<int> cmp;

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mx = max(seg[idx].mx, v);
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upd(p, v, 2*idx);
	}
	else {
		upd(p, v, 2*idx+1);
	}
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

int query(int l, int r, int idx){
	if(r < l){
		return 0;
	}
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mx;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return max(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		cmp.push_back(arr[i]);
	}
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	for(int i = 1; i<=N; i++){
		arr[i] = lower_bound(cmp.begin(), cmp.end(), arr[i]) - cmp.begin() + 1;
		pos[arr[i]].push_back(i);
	}
	fill(mn, mn+2+N, N+1);
	for(int i = 1; i<=N; i++){
		for(int j = 3; j<pos[i].size(); j++){
			if(mn[pos[i][j-3]] > pos[i][j]){
				mn[pos[i][j-3]] = pos[i][j];
				bst[pos[i][j-3]] = make_pair(i, i);
			}
			//mn[pos[i][j-3]] = min(mn[pos[i][j-3]], pos[i][j]);
		}
	}
	build(1, N, 1);
	for(int i = 1; i<=N; i++){
		int idx = lower_bound(pos[arr[i]].begin(), pos[arr[i]].end(), i) - pos[arr[i]].begin();
		if(idx+1 != pos[arr[i]].size()){
			int k = query(i+1, pos[arr[i]][idx+1], 1);
			//cout << i << " " << k << "\n";
			if(k && pos[arr[i]][idx+1] < mn[k]){
				mn[k] = pos[arr[i]][idx+1];
				bst[k] = make_pair(arr[k], arr[i]);
				//cout << " " << arr[k] << " " << arr[i] << "\n";
			}
			upd(pos[arr[i]][idx+1], i, 1);
			upd(i, 0, 1);
		}
	}
	for(int i = N; i; i--){
		if(mn[i] > mn[i+1]){
			mn[i] = mn[i+1];
			bst[i] = bst[i+1];
		}
	}
	int ans = 0;
	int crnt = 1;	
	vector<int> out;
	while(crnt != N+1){
		if(mn[crnt] == N+1){
			break;
		}
		ans++;
		out.push_back(bst[crnt].first);
		out.push_back(bst[crnt].second);
		out.push_back(bst[crnt].first);
		out.push_back(bst[crnt].second);		
		crnt = mn[crnt] + 1;
	}
	cout << 4*ans << "\n";
	for(int n : out){
		cout << cmp[n-1] << " ";
	}
}