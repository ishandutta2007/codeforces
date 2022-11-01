#define _USE_MATH_DEFINES
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


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int n,m;

char maze[4500][4501];
Pii first[1500][1501];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main()
{
	int tx,ty;
	cin>>n>>m;
	for(int i= 0; i < n; i++){
		cin>>maze[i];
		for (int k = 0; k < m; k++){
			if(maze[i][k] == 'S'){
				ty = i;
				tx = k;
			}
		}
	}

	int px = tx + m * 1500;
	int py = ty + n * 1500;
	memset(first,-1,sizeof(first));
	stack<int> sx,sy;
	sx.push(px); sy.push(py);

	while(!(sx.empty())){
		int x = sx.top(),y = sy.top();
		sx.pop(); sy.pop();

		if(first[y%n][x%m].first == -1){
			first[y%n][x%m].first = x;
			first[y%n][x%m].second = y;
		} else if(x != first[y%n][x%m].first || y != first[y%n][x%m].second){
			puts("Yes");
			return 0;
		}

		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(nx == first[ny % n][nx % m].first && ny == first[ny % n][nx % m].second) 
				continue;
			if(maze[ny % n][nx % m] == '#')
				continue;
			sx.push(nx); sy.push(ny);
		}
	}

	puts("No");

	return 0;
}