///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 2010;
char a[N][N];
int cnt[N][N];
int n, m;
queue<pii> q;

bool hok(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m;
}
bool ok(int i, int j){
	return 0 <= i && i < n && 0 <= j && j < m && a[i][j] == '.';
}

void up(int i, int j){
	if(!hok(i,j)) return;
	cnt[i][j] = 0;
	if(!ok(i,j)) return;
	for(auto [x, y] : {pii{0,-1},{0,1},{-1,0},{1,0}})
		cnt[i][j] += ok(i+x,j+y);
	if(cnt[i][j] == 0) Kill("Not unique");
	if(cnt[i][j] == 1) q.push({i,j});
}

void match(int i, int j){
	if(!ok(i,j)) return;
	for(auto [x, y, c1, c2] : {tuple<int,int,char,char>{0,-1,'>','<'},{0,1,'<','>'},{-1,0,'v','^'},{1,0,'^','v'}}){
		if(ok(i+x,j+y)){
			a[i][j] = c1;
			a[i+x][j+y] = c2;
			for(auto [a, b] : {pii{0,-1},{0,1},{-1,0},{1,0}}){
				up(i+a,j+b);
				up(i+x+a,j+y+b);
			}
			return;
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,n) Loop(j,0,m) up(i,j);
	while(q.size()){
		auto [i, j] = q.front(); q.pop();
		match(i,j);
	}
	Loop(i,0,n) Loop(j,0,m) if(a[i][j] == '.') Kill("Not unique");
	Loop(i,0,n) cout << a[i] << '\n';
}