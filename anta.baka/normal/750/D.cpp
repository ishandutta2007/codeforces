#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int dx[] = { 0,-1,-1,-1,0,1,1, 1};
const int dy[] = {-1,-1, 0, 1,1,1,0,-1};

struct pt {
	int x, y, w, lvl;
	pt(int X, int Y, int W, int LVL) : x(X), y(Y), w(W), lvl(LVL) {}
	bool operator < (const pt & a) const {
		return x<a.x||x==a.x&&y<a.y||x==a.x&&y==a.y&&w<a.w||x==a.x&&y==a.y&&w==a.w&&lvl<a.lvl;
	}
};

int n;
int t[30];
set<pt> mem;
set<pii> res;

void go(int x, int y, int w, int lvl) {
	if(lvl == n)
		return;
	for(int i = 0; i < t[lvl]; i++) {
		x += dx[w];
		y += dy[w];
		res.insert({x,y});
	}
	pt l(x,y,(w+7)%8,lvl+1);
	pt r(x,y,(w+1)%8,lvl+1);
	bool gol = false;
	if(mem.find(l) == mem.end()) {
		mem.insert(l);
		gol = true;
	}
	if(mem.find(r) == mem.end()) {
		mem.insert(r);
		go(x,y,(w+1)%8,lvl+1);
	}
	if(gol == true)
		go(x,y,(w+7)%8,lvl+1);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i];
	mem.insert(pt(0,-1,4,0));
	go(0,-1,4,0);
	cout << res.size();
}