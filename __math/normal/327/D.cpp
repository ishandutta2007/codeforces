#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

struct A{
	char a;
	int x,y;
	A(char a,int x,int y) : a(a) , x(x), y(y) {}
	A(){}
};

int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
int n,m;
char board[500][510];
Pii par[500][500];
vector<A> ans;

void bfs(int fx,int fy){
	queue<Pii> q;
	vector<Pii> use;
	q.push(Pii(fx,fy));
	use.push_back(Pii(fx,fy));
	par[fy][fx] = Pii(-2,-2);
	while(!q.empty()){
		Pii p = q.front(); q.pop();
		int x = p.first,y = p.second;
		FOR(i,4){
			int nx = x + dx[i],ny = y + dy[i];
			if(0 <= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == '.'){
				if(par[ny][nx].first == -1){
					par[ny][nx].first = x;
					par[ny][nx].second = y;
					q.push(Pii(nx,ny));
					use.push_back(Pii(nx,ny));
				}
			}
		}
	}

	FOR(i,sz(use)){
		ans.push_back(A('B',use[i].first,use[i].second));
	}
	for(int i = sz(use)-1; i > 0; i--){  
		Pii &P = use[i];
		ans.push_back(A('D',P.first,P.second));
		ans.push_back(A('R',P.first,P.second));
	}
}

int main(){
	cin>>n>>m;
	FOR(i,n) cin>>board[i];
	FOR(i,n) FOR(j,m) par[i][j].first = par[i][j].second = -1;

	FOR(i,n) FOR(j,m){
		if(board[i][j] == '.' && par[i][j].first == -1){
			bfs(j,i);
		}
	}

	cout << sz(ans) << endl;
	FOR(i,sz(ans)){
		printf("%c %d %d\n",ans[i].a,ans[i].y+1,ans[i].x+1);
	}

	return 0;
}