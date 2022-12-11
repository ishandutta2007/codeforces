
// Problem : F. Souvenirs
// Contest : Codeforces - Codeforces Round #397 by Kaspersky Lab and Barcelona Bootcamp (Div. 1 + Div. 2 combined)
// URL : https://codeforces.com/problemset/problem/765/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	int mx;
	vector<int> idx, val;
};

node seg[400005];
int N;
const int oo = INT_MAX/2;
int arr[100005];
vector<int> v[3][100005];
vector<int> cmp;
//set<pair<int, int>> st;

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l ==r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mx = v;
		return;
	}
	upd(p, v, 2*idx+((seg[idx].l+seg[idx].r)/2 < p));
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

int getmx(int l, int r, int idx){
	if(l > r){
		return 0;
	}
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mx;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return getmx(l, r, 2*idx);
	}
	else if(l > mid){
		return getmx(l, r, 2*idx+1);
	}
	else{
		return max(getmx(l, mid, 2*idx), getmx(mid+1, r, 2*idx+1));
	}
}

void constr(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(seg[idx].l == seg[idx].r){
		for(int n : v[2][seg[idx].l]){
			seg[idx].idx.push_back(n);
			seg[idx].val.push_back(abs(arr[n]-arr[seg[idx].l]));
			//cout << seg[idx].l << " " << n << " " << abs(arr[n]-arr[seg[idx].l]) << "\n";
		}
		return;
	}
	int mid = l+r>>1;
	constr(l, mid, 2*idx);
	constr(mid+1, r, 2*idx+1);
	int idx0 = 0, idx1 = 0;
	while(idx0 < seg[2*idx].val.size() || idx1 < seg[2*idx+1].val.size()){
		int opt0 = (idx0 < seg[2*idx].val.size() ? seg[2*idx].idx[idx0] : 0);
		int opt1 = (idx1 < seg[2*idx+1].val.size() ? seg[2*idx+1].idx[idx1] : 0);
		if(opt0 > opt1){
			if(seg[idx].val.empty() || seg[idx].val.back() > seg[2*idx].val[idx0]){
				seg[idx].val.push_back(seg[2*idx].val[idx0]);
				seg[idx].idx.push_back(seg[2*idx].idx[idx0]);
			}
			idx0++;
		}
		else{
			if(seg[idx].val.empty() || seg[idx].val.back() > seg[2*idx+1].val[idx1]){
				seg[idx].val.push_back(seg[2*idx+1].val[idx1]);
				seg[idx].idx.push_back(seg[2*idx+1].idx[idx1]);
			}
			idx1++;
		}
	}
}

int query(int l, int r, int lim, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		int ll = 0, rr = seg[idx].val.size();
		rr--;
		int ret = oo;
		while(ll <= rr){
			int mm = ll+rr>>1;
			if(seg[idx].idx[mm] >= lim){
				ret = seg[idx].val[mm];
				ll = mm + 1;
			}
			else{
				rr = mm - 1;
			}
		}
		return ret;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, lim, 2*idx);
	}
	else if(l > mid){
		return query(l, r, lim, 2*idx+1);
	}
	else{
		return min(query(l, mid, lim, 2*idx), query(mid+1, r, lim, 2*idx+1));
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
	build(1, N, 1);
	for(int i = 1; i<=N; i++){
		/*
		int crnt = 0;
		//cout << seg[1].mn << " " << seg[1].mx << endl;
		cout << "index: " << i << "\n";
		while(seg[1].mn >= crnt && seg[1].mn <= arr[i]){
			int idx = walk(0, crnt, arr[i], 1);
			cout << idx << "\n";
			v[0][i].push_back(idx);
			if(arr[idx] == arr[i]){
				break;
			}
			crnt = (arr[idx]+(arr[i]-arr[idx]+1)/2);
		}
		crnt = oo;
		while(seg[1].mx <= crnt && seg[1].mx >= arr[i]){
			//cout << crnt << endl;
			int idx = walk(1, crnt, arr[i], 1);
			cout << idx << endl;
			v[1][i].push_back(idx);
			if(arr[idx] == arr[i]){
				break;
			}
			crnt = (arr[idx]-(arr[idx]-arr[i]+1)/2);
		}
		upd(i, arr[i], 1);
		*/
		/*
		int crnt = 0;
		while(crnt <= arr[i]){
			auto it = st.lower_bound(make_pair(crnt, 0));
			if(it == st.end() || (*it).first > arr[i]){
				break;
			}
			v[0][i].push_back((*it).second);
			if((*it).first == arr[i]){
				break;
			}
			crnt = max((*it).first+1, (*it).first+(arr[i]-(*it).first)/2);
			//crnt = (*it).first+1;
		}
		crnt = oo;
		while(crnt >= arr[i]){
			auto it = st.upper_bound(make_pair(crnt, 2*N));
			if(it == st.begin() || (*(--it)).first < arr[i]){
				break;
			}
			v[1][i].push_back((*it).second);
			//cout << (*it).second << " " << i << "\n";
			if((*it).first == arr[i]){
				break;
			}
			crnt = min((*it).first-1, (*it).first-((*it).first-arr[i])/2);
			//crnt = (*it).first-1;
			//cout << crnt << "\n";
		}
		sort(v[0][i].begin(), v[0][i].end(), greater<int>());
		sort(v[1][i].begin(), v[1][i].end(), greater<int>());
		auto ptr = st.lower_bound(make_pair(arr[i], 0));
		if(ptr != st.end() && (*ptr).first == arr[i]){
			st.erase(ptr);
		}
		st.insert(make_pair(arr[i], i));
		*/
		int crnt = 0;
		int org = lower_bound(cmp.begin(), cmp.end(), arr[i]) - cmp.begin() + 1;
		while(crnt <= arr[i]){
			int p = lower_bound(cmp.begin(), cmp.end(), crnt) - cmp.begin() + 1;
			int t = getmx(p, org, 1);
			if(t == 0){
				break;
			}
			v[0][i].push_back(t);
			if(arr[t] == arr[i]){
				break;
			}
			crnt = arr[t]+(arr[i]-arr[t]+1)/2;
		}
		crnt = oo;
		while(crnt >= arr[i]){
			int p = upper_bound(cmp.begin(), cmp.end(), crnt) - cmp.begin();
			int t = getmx(org, p, 1);
			if(t == 0){
				break;
			}
			v[1][i].push_back(t);
			if(arr[t] == arr[i]){
				break;
			}
			crnt = arr[t]-(arr[t]-arr[i]+1)/2;
		}
		upd(org, i, 1);
		int idx0 = 0, idx1 = 0;
		while(idx0 < v[0][i].size() || idx1 < v[1][i].size()){
			int opt0 = (idx0 < v[0][i].size() ? v[0][i][idx0] : 0);
			int opt1 = (idx1 < v[1][i].size() ? v[1][i][idx1] : 0);
			if(opt0 > opt1){
				int delta = arr[i] - arr[opt0];
				if(v[2][i].empty() || abs(arr[v[2][i].back()]-arr[i]) > delta){
					v[2][i].push_back(opt0);
				}
				idx0++;
			}
			else{
				int delta = arr[opt1] - arr[i];
				if(v[2][i].empty() || abs(arr[v[2][i].back()]-arr[i]) > delta){
					v[2][i].push_back(opt1);
				}
				idx1++;
			}
		}
	}
	constr(1, N, 1);
	int Q;
	cin >> Q;
	while(Q--){
		int l, r;
		cin >> l >> r;
		cout << query(l, r, l, 1) << "\n";
	}
}