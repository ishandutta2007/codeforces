#include <bits/stdc++.h>
 
using namespace std;

struct segMinL{ //with lazy, beaware of max value = INT_MAX/3
	vector<int> tree, lazy;
	int size;
	segMinL(int size){
		this->size = size;
		tree = vector<int>(size*4 + 1, 0);
		lazy = vector<int>(size*4 + 1, 0);
	}
		
	void prop(int i, int start, int end){
		tree[i] += lazy[i];
		if(start != end){
			lazy[i*2] +=  lazy[i];
			lazy[i*2+1] +=  lazy[i];
		}
		lazy[i] = 0;
	}
	
	int query(int i, int s, int e, int l, int r){
		prop(i, s, e);
		if(s >= l && e <= r){
			return tree[i];
		}
		if(e < l || s > r) return INT_MAX;
		int m = (s + e)/2;
		return min(query(i*2, s, m, l, r), query(i*2+1, m+1, e, l, r));
	}
	
	void upd(int i, int s, int e, int l, int r, int val){
		prop(i, s, e);
		if(s > r || e < l || s > e) return;
		if(s >= l && e <= r){
			lazy[i] += val;
			prop(i,s, e);
			return;
		}
		int m = (s + e)/2;
		upd(i*2, s, m, l, r, val);
		upd(i*2+1, m+1, e, l, r, val);
		tree[i] = min(tree[i*2], tree[i*2+1]);
	}	
	
	int query(int l, int r){
		return query(1, 0, size-1, max(l, 0), min(r, size-1));
	}
	void upd(int l, int r, int val){
		upd(1, 0, size-1, max(l, 0), min(r, size-1), val);
	}
};




struct point{
	int x, y, flip;
};

bool comp(point a, point b){
	if(a.x == b.x){
		if(a.flip == b.flip)
			return a.y < b.y;	
		else return a.flip == 1;
	} 
	else return a.x < b.x;
}


signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, r; cin>>n>>r;
	r = 2*r;
	vector<point> p(n);
	for(int i = 0; i < n; i++){
		int a, b; cin>>a>>b;
		p[i].x = a - b;
		p[i].y = a + b+2e6+5;
		p[i].flip = 1;
		p.push_back(p[i]);
		p.back().flip = -1;
		p.back().x += r;
	}
	
	sort(p.begin(), p.end(), comp);
//	for(point c: p){
//		cout<<"ARR: "<<c.x<<" "<<c.y<<" "<<c.flip<<endl;
//	}
	segMinL segtree(4e6+100);
	int ans = 1;
	for(int i = 0; i < p.size(); i++){
		if(p[i].flip == -1){
			//remvove the point
			segtree.upd(p[i].y, p[i].y + r, +1);
//			/cout<<"ERASING  "<<p[i].y-r<<" "<<p[i].y+r<<endl;
		//	cout<<"eRASED "<<p[i].y<<" "<<p[i].x-r<<endl;
		}else{
			//insert point
			
			segtree.upd(p[i].y, p[i].y+ r, -1);
			//cout<<"UDPING "<<p[i].y-r<<" "<<p[i].y+r<<endl;
			int val = -segtree.query(0, segtree.size-1);
			//cout<<"CUR "<<val<<endl;
			ans = max(ans, val);
		}
	}
	cout<<ans<<endl;
}