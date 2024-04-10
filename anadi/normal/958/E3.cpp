#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y, nr;
	bool t;
};

const int N = 2e4 + 7;

int n, m;
int ans[N];
Point tab[N];

bool cmp(Point a, Point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int xr, yr;
void change(Point &a){
	xr = a.x;
	yr = a.y;
}

bool cmp2(Point a, Point b){
	return (a.x - xr) * (b.y - yr) < (b.x - xr) * (a.y - yr);
}

void wczytaj(int a){
	scanf("%d %d", &tab[a].x, &tab[a].y);
	tab[a].nr = a;

	if(a > n){
		tab[a].t = true;
		tab[a].nr -= n;
	}
}

void connect(int x, int y){
	if(tab[x].t)
		ans[tab[y].nr] = tab[x].nr;
	else
		ans[tab[x].nr] = tab[y].nr;
}

void solve(int from, int to){
	if(from > to)
		return;
	
	assert((to - from)%2 == 1);
	if(from + 1 == to){
		connect(from, to);
		return;
	}
	
	int id = min_element(tab + from, tab + to + 1, cmp) - tab;
	swap(tab[id], tab[from]);

	change(tab[from]);
	sort(tab + from + 1, tab + to + 1, cmp2);
	
	int pref = 0, mid = 0;
	for(int i = from + 1; i <= to; ++i){
		if(tab[i].t != tab[from].t && pref == 0){
			mid = i;
			break;
		}
		
		pref += tab[i].t ? 1 : -1;
	}
	
	assert(mid != 0);
	connect(from, mid);
	
	solve(from + 1, mid - 1);
	solve(mid + 1, to);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		wczytaj(i);
	for(int i = 1; i <= n; ++i)
		wczytaj(n + i);
	solve(1, 2 * n);
	
	for(int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}