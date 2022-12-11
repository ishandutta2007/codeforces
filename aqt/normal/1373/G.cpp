
// Problem : G. Pawns
// Contest : Codeforces - Educational Codeforces Round 90 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1373/G
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

//Kevin Wan's Solution
struct node{
	int l, r, mx, lzy;// gmx, gidx;
};

int N, K, Q;
node seg[2000000];
int cnt[1000000];
set<pair<int, int>> st;

/*
void pu(int idx){
	if(seg[2*idx].gmx+seg[2*idx].gidx > seg[2*idx+1].gmx+seg[2*idx+1].gidx){
		seg[idx].gmx = seg[2*idx].gmx;
		seg[idx].gidx = seg[2*idx].gidx;
	}
	else{
		seg[idx].gmx = seg[2*idx+1].gmx;
		seg[idx].gidx = seg[2*idx+1].gidx;
	}
	if(!seg[2*idx].mx){
		seg[idx].mx = seg[2*idx+1].mx;
		seg[idx].idx = seg[2*idx+1].idx;
	}
	else if(!seg[2*idx+1].mx){
		seg[idx].mx = seg[2*idx].mx;
		seg[idx].idx = seg[2*idx].idx;
	}
	else if(seg[2*idx].mx+seg[2*idx].idx > seg[2*idx+1].mx+seg[2*idx+1].idx){
		seg[idx].mx = seg[2*idx].mx;
		seg[idx].idx = seg[2*idx].idx;
	}
	else{
		seg[idx].mx = seg[2*idx+1].mx;
		seg[idx].idx = seg[2*idx+1].idx;
	}
	//cout << idx << " " << seg[idx].mx << " " << seg[idx].idx << "\n";
	//cout << seg[2*idx+1].mx << " " << seg[2*idx+1].idx << "\n";
	//cout << seg[2*idx].mx << " " << seg[2*idx].idx << "\n";
}
*/
/*
void pu(int idx){
	seg[idx].idx = seg[2*idx].idx;
	seg[idx].mx = seg[2*idx].mx;
	seg[idx].gmx = seg[2*idx].gmx;
	seg[idx].gidx = seg[2*idx].gidx;
	if(seg[2*idx+1].mx && seg[idx].idx + seg[idx].mx <= seg[2*idx+1].idx + seg[2*idx+1].mx){
		if(seg[idx].mx != seg[2*idx+1].mx){
			seg[idx].gmx = seg[idx].mx;
			seg[idx].gidx = seg[idx].idx;
		}
		seg[idx].mx = seg[2*idx+1].mx;
		seg[idx].idx = seg[2*idx+1].idx;
	}
	else if(seg[2*idx+1].mx + seg[2*idx+1].idx > seg[idx].)
}
*/

void pu(int idx){
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].mx += seg[idx].lzy;
		seg[2*idx+1].mx += seg[idx].lzy;
		//seg[2*idx].gmx += seg[idx].lzy;
		//seg[2*idx+1].gmx += seg[idx].lzy;
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void build(int l, int r, int idx){
	//cout << l << " " << r << " " << idx << "\n";
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		//seg[idx].mx = 0;
		//seg[idx].idx = l;
		//seg[idx].gmx = 0;
		//seg[idx].gidx = r;
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	//pu(idx);
}

void upd(int l, int r, int v, int idx){
	//cout << idx << endl;
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mx += v;
		seg[idx].lzy += v;
		/*
		seg[idx].gmx += v;
		if(seg[idx].gmx && seg[idx].gmx + seg[idx].gidx > seg[idx].mx + seg[idx].idx){
			swap(seg[idx].gmx, seg[idx].mx);
			swap(seg[idx].gidx, seg[idx].idx);
		}
		if(!seg[idx].mx){
			swap(seg[idx].gmx, seg[idx].mx);
			swap(seg[idx].gidx, seg[idx].idx);
		}
		*/
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	pu(idx);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> Q;
	build(1, 2*N, 1);
	while(Q--){
		int x, y;
		cin >> x >> y;
		int i = y+abs(K-x);
		if(st.count(make_pair(x, y))){
			cnt[i]--;
			if(!cnt[i]){
				upd(i, i, -i+1, 1);
			}
			upd(1, i, -1, 1);
			st.erase(make_pair(x, y));
		}
		else{
			cnt[i]++;
			//upd(1, i, (cnt[i] == 1 ? 1 : i), 1);
			if(cnt[i] == 1){
				upd(i, i, i-1, 1);
			}
			upd(1, i, 1, 1);
			st.insert(make_pair(x, y));
		}
		if(seg[1].mx){
			//cout << Q << " " << seg[1].mx << " " << seg[1].idx << "\n";
			cout << max(0, seg[1].mx-N) << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}