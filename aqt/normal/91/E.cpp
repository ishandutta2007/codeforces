
// Problem : E. Igloo Skyscraper
// Contest : Codeforces Beta Round #75 (Div. 1 Only)
// URL : https://codeforces.com/contest/91/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 3000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	vector<pair<long long, long long>> v;
	vector<int> idx;
};

int N, Q;
node seg[400005];
pair<long long, long long> arr[100005];

long double getint(int a, int b){
	return 1.0*(arr[a].second-arr[b].second)/(1.0*arr[b].first-arr[a].first);
}

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		seg[idx].v.push_back(arr[l]);
		seg[idx].idx.push_back(l);
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	int idx1 = 0, idx2 = 0;
	while(idx1 < seg[2*idx].v.size() || idx2 < seg[2*idx+1].v.size()){
		pair<int, int> p;
		int k;
		if(idx2 == seg[2*idx+1].v.size() || (idx1 < seg[2*idx].v.size() && seg[2*idx].v[idx1] < seg[2*idx+1].v[idx2])){
			p = seg[2*idx].v[idx1];
			k = seg[2*idx].idx[idx1++];
		}
		else{
			p = seg[2*idx+1].v[idx2];
			k = seg[2*idx+1].idx[idx2++];
		}
		while(seg[idx].v.size() >= 2){
			int b = seg[idx].idx.back();
			seg[idx].idx.pop_back();
			//cout << "hi: " << seg[idx].l << " " << seg[idx].r << " " << getint(seg[idx].idx.back(), b) << " " << getint(seg[idx].idx.back(), k) << "\n";
			//cout << seg[idx].idx.back() << " " << b << " " << k << "\n";
			if(arr[b].first == arr[k].first || getint(seg[idx].idx.back(), b) >= getint(seg[idx].idx.back(), k)){
				seg[idx].v.pop_back();
			}
			else{
				seg[idx].idx.push_back(b);
				break;
			}
		}
		if(seg[idx].v.size() && seg[idx].v.back().first == p.first){
			seg[idx].v.pop_back();
			seg[idx].idx.pop_back();
		}
		seg[idx].idx.push_back(k);
		seg[idx].v.push_back(arr[k]);
	}
}

long long query(int l, int r, long long x, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		long long ans = 0;
		int lft = 0, rht = seg[idx].v.size()-1;
		while(lft <= rht){
			int mid = lft+rht>>1;
			long long a = x*seg[idx].v[mid].first + seg[idx].v[mid].second;
			int temp = min(mid+1, (int) (seg[idx].v.size()-1));
			long long b = x*seg[idx].v[temp].first + seg[idx].v[temp].second;
			if(a > b){
				ans = a > arr[ans].first*x+arr[ans].second ? seg[idx].idx[mid] : ans;
				rht = mid - 1;
			}
			else{
				ans = b > arr[ans].first*x+arr[ans].second ? seg[idx].idx[temp] : ans;
				lft = mid + 2;
			}
		}
		return ans;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, x, 2*idx);
	}
	else if(l > mid){
		return query(l, r, x, 2*idx+1);
	}
	else{
		auto p = query(l, mid, x, 2*idx), q = query(mid+1, r, x, 2*idx+1);
		if(arr[p].first*x+arr[p].second < arr[q].first*x+arr[q].second){
			return q;
		}
		else{
			return p;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].second >> arr[i].first;
	}
	build(1, N ,1);
	while(Q--){
		int l, r, x;
		cin >> l >> r >> x;
		cout << query(l, r, x, 1) << "\n";
	}
}