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


using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int n,m;

vector<Pii> e[100];
int color[100] ={}; //0 or 2 or 3   ---- 0 ---> not visited
bool has_error = false;

void dfs(int x,int f){

	color[x] = f;
	FOR(i,sz(e[x])){
		if(has_error) return ;
		int next = e[x][i].second ? f : (f^1);
		if(color[e[x][i].first] == 0){
			dfs(e[x][i].first,next);
			if(has_error) return ;
		} else {
			if(color[e[x][i].first] != next){
				has_error = true;
				return ;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	FOR(i,m){
		int a,b,c; cin>>a>>b>>c;
		a--;b--;
		e[a].push_back(Pii(b,c));
		e[b].push_back(Pii(a,c));
	}
	FOR(i,n){
		if(color[i] == 0)
			dfs(i,2);
		if(has_error) break;
	}

	if(has_error){
		puts("Impossible");
	} else {
		vector<int> ans;
		FOR(i,n){
			if(color[i] == 2) ans.push_back(i+1);
		}
		cout << ans.size() << endl;
		FOR(i,sz(ans)){
			cout << ans[i];
			if(i == sz(ans)-1) cout << endl;
			else cout << " ";
		}
	}

	return 0;
}