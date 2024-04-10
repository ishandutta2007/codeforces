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
const int N = 500002;

int n, m, next_[N];
vector <int> e[N];
vector <vector <int> > ans;

//vZA^-1(n,n)?(AbJ[})
//union_findfindS
int find_next(int i) {
    if (next_[i] != i) { //gw
		//wvZ
        next_[i] = find_next(next_[i]);
    }
    return next_[i];
}

void dfs(int a){
	next_[a] = a + 1; //w
	ans.back().push_back(a); //_
	vector<int>::iterator it = e[a].begin();
	for(int i = find_next(1); i <= n; i = find_next(i + 1)){
		//iAqm_
		
		//\[gedgeA*itiA~ *it == i `FbNgl*it
		while(it != e[a].end() && *it < i) 
			++it;

		//endv(edge) or *it != i(ivedge)
		if(it == e[a].end() || *it != i){
			dfs(i);
		}
	}
}

int main() {
	//input
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
		//edge
        e[a].push_back(b);
        e[b].push_back(a);
    }
	//next_ table init , sort edge
	//O(n log(n) )
    for (int i = 1; i <= n; ++ i) {
        next_[i] = i;
        sort(e[i].begin(), e[i].end());
    }
    next_[n + 1] = n + 1;
	//dfs([DT) A_(city)m
    for (int i = 1; i <= n; ++ i) {
        if (next_[i] == i) { //T_
			//opvector
            ans.push_back(vector <int>());
			//dfss
            dfs(i);
        }
    }

	//answer
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); ++ i) {
        printf("%d", (int)ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); ++ j) {
            printf(" %d", ans[i][j]);
        }
        puts("");
    }
    return 0;
}