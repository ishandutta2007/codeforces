#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n;
vector <int> xd;
vector <vector <int> > res;

inline void add3(int x, int y, int z){
	xd.clear();
	xd.pb(x), xd.pb(y), xd.pb(z);
	res.pb(xd);
}

inline void add4(int w, int x, int y, int z){
	xd.clear();
	xd.pb(w), xd.pb(x), xd.pb(y), xd.pb(z);
	res.pb(xd);
}



void solve(vector <int> cur){
	if(cur.size() == 3){
		add3(cur[0], cur[1], cur[2]);
		add3(cur[0], cur[1], cur[2]);
		return;
	}
	
	if(cur.size() ==  4){
		int a = cur[0], b = cur[1], c = cur[2], d = cur[3];
		add3(a, b, c);
		add3(b, c, d);
		add3(c, d, a);
		add3(d, a, b);
		return;
	}
	
	if(!(cur.size() & 1)){
		int x = cur.back();	cur.pop_back();
		int y = cur.back();	cur.pop_back();
		
		add3(x, cur[0], y);
		add3(x, cur[1], y);
		add4(x, cur[0], y, cur[1]);

		for(int i = 2; i < cur.size(); i += 2){
			add4(x, cur[i], y, cur[i + 1]);
			add4(x, cur[i], y, cur[i + 1]);
		}
		
		solve(cur);
		return;
	}
	
	if(cur.size() & 1){
		int x = cur.back();	cur.pop_back();
		int y = cur.back(); cur.pop_back();
		
		add3(x, cur[0], y);
		add3(x, cur[0], y);
		
		for(int i = 1; i < cur.size(); i += 2){
			add4(x, cur[i], y, cur[i + 1]);
			add4(x, cur[i], y, cur[i + 1]);
		}
		
		solve(cur);
		return;
	}
}

void write(){
	printf("%d\n", res.size());
	for(int i = 0; i < res.size(); ++i){
		printf("%d ", res[i].size());
		for(int v: res[i])
			printf("%d ", v);
		puts("");
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		xd.pb(i);
	solve(xd);
	write();
	return 0;
}