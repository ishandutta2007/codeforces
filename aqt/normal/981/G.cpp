
// Problem : G. Magic multisets
// Contest : Codeforces - Avito Code Challenge 2018
// URL : https://codeforces.com/problemset/problem/981/G
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long lzys, lzyp, sum;
};

int N, Q;
set<pair<int, int>> st[200005];
node seg[1000005];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	seg[idx].lzyp = 1;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void pd(int idx){
	if(seg[idx].lzyp != 1){
		for(int nxt = 2*idx; nxt<=2*idx+1; nxt++){
			seg[nxt].lzyp = mult(seg[nxt].lzyp, seg[idx].lzyp);
			seg[nxt].lzys = mult(seg[nxt].lzys, seg[idx].lzyp);
			seg[nxt].sum = mult(seg[nxt].sum, seg[idx].lzyp);
		}
		seg[idx].lzyp = 1;
	}
	if(seg[idx].lzys){
		for(int nxt = 2*idx; nxt<=2*idx+1; nxt++){
			seg[nxt].lzys = add(seg[nxt].lzys, seg[idx].lzys);
			seg[nxt].sum = add(seg[nxt].sum, mult(seg[idx].lzys, seg[nxt].r-seg[nxt].l+1));
		}
		seg[idx].lzys = 0;
	}
}

void upd(int l, int r, int v, bool p, int idx){
	//cout << l << " " << r << endl;
	assert(l <= r);
	if(seg[idx].l == l && seg[idx].r == r){
		if(p){
			seg[idx].sum = mult(seg[idx].sum, v);
			seg[idx].lzys = mult(seg[idx].lzys, v);
			seg[idx].lzyp = mult(seg[idx].lzyp, v);
		}
		else{
			seg[idx].sum = add(seg[idx].sum, mult(v, seg[idx].r-seg[idx].l+1));
			seg[idx].lzys = add(seg[idx].lzys, v);
		}
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(r <= mid){
		upd(l, r, v, p, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, p, 2*idx+1);
	}
	else{
		upd(l, mid, v, p, 2*idx);
		upd(mid+1, r, v, p, 2*idx+1);
	}
	seg[idx].sum = add(seg[2*idx].sum, seg[2*idx+1].sum);
}

long long query(int l, int r, int idx){
	assert(l <= r);
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].sum;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return add(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	build(1, N, 1);
	while(Q--){
		int c, l, r;
		cin >> c >> l >> r;
		if(c == 1){
			int v;
			cin >> v;
			//cout << (st[v].lower_bound({l, 0}) == st[v].end()) << endl;
			for(auto ptr = st[v].lower_bound({l, 0}); ptr != st[v].end(); ptr = st[v].erase(ptr)){
				if((*ptr).second <= r){
					//cout << (*ptr).first << " " << (*ptr).second << endl;
					//cout << "here" << endl;
					upd((*ptr).first, (*ptr).second, 2, 1, 1);
					upd((*ptr).first, (*ptr).second, MOD-1, 0, 1);
					continue;
				}
				else if((*ptr).first <= r){
					//cout << "here" << endl;
					upd((*ptr).first, r, 2, 1, 1);
					upd((*ptr).first, r, MOD-1, 0, 1);
				}
				break;
			}
			auto ptr = st[v].lower_bound({l, 0});
			//cout << (ptr == st[v].begin()) << endl;
			if(ptr != st[v].begin()){
				ptr--;
				if((*ptr).second >= l){
					//cout << "here" << endl;
					//cout << " " << l << " " << (*ptr).second << endl;
					upd(l, min(r, (*ptr).second), 2, 1, 1);
					upd(l, min(r, (*ptr).second), MOD-1, 0, 1);
				}
			}
			upd(l, r, 1, 0, 1);
			ptr = st[v].lower_bound({l, 0});
			if(ptr != st[v].end() && (*ptr).first <= r){
				assert((*ptr).second >= r);
				r = (*ptr).second;
				ptr = st[v].erase(ptr);
			}
			if(ptr != st[v].begin() && (*(--ptr)).second >= l){
				assert((*ptr).first <= l);
				l = (*ptr).first;
				r = max((*ptr).second, r);
				st[v].erase(ptr);
			}
			assert(l <= r);
			//cout << l << " " << r << "\n";
			st[v].insert({l, r});
			//cout << query(1, N, 1) << "\n";
		}
		else{
			cout << query(l, r, 1) << "\n";
		}
		//cout << "qu: " << 35-Q << "\n";
	}
}