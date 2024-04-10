
// Problem : F2. Chess Strikes Back (hard version)
// Contest : Codeforces - Codeforces Round #657 (Div. 2)
// URL : https://codeforces.com/contest/1379/problem/F2
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	int loA, hiB;
	bool good;
};

Node seg[1000000];
int N, M, Q;
set<int> stA[200005], stB[200005];
set<pair<int, int>> st;

void build(int l, int r, int idx){
	seg[idx].good = 1;
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].hiB = 1e9;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int p, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].loA = (stA[p].empty() ? 0 : *stA[p].rbegin());
		seg[idx].hiB = (stB[p].empty() ? 1e9 : *stB[p].begin());
		//cout << seg[idx].loA << " " << seg[idx].hiB << "\n";
		seg[idx].good = seg[idx].loA < seg[idx].hiB;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upd(p, 2*idx);
	}
	else{
		upd(p, 2*idx+1);
	}
	seg[idx].good = seg[2*idx+1].loA < seg[2*idx].hiB;
	seg[idx].loA = max(seg[2*idx].loA, seg[2*idx+1].loA);
	seg[idx].hiB = min(seg[2*idx].hiB, seg[2*idx+1].hiB);
	seg[idx].good &= (seg[2*idx].good && seg[2*idx+1].good);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	build(1, M, 1);
	while(Q--){
		int x, y;
		cin >> x >> y;
		swap(x, y);
		if(st.count(make_pair(x, y))){
			st.erase(make_pair(x, y));
			bool isB = x%2 == 1;
			x = (x+1)/2;
			y = (y+1)/2;
			if(!isB){
				stA[x].erase(y);
			}
			else{
				stB[x].erase(y);
			}
		}
		else{
			st.insert(make_pair(x, y));
			bool isB = x%2 == 1;
			x = (x+1)/2;
			y = (y+1)/2;
			if(!isB){
				stA[x].insert(y);
			}
			else{
				stB[x].insert(y);
			}
		}
		upd(x, 1);
		if(seg[1].good){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}