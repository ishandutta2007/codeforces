#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e3 + 10;
const int inf = 1e9;

int a[maxn][maxn];
int c[maxn * maxn];
vector < int > stack;
int t = 0;
int n, m;

bool solve(int k){
    for(int i = 0; i < n; i++){
	stack.clear();
	for(int j = 0; j < m; j++){
	    if (a[i][j] >= k){
		for(int i1 = 0; i1 < (int)stack.size(); i1++){
		    int hash = stack[i1] * m + j;
		    if (c[hash] == t)
			return 1;
		    c[hash] = t;
		}
		stack.pb(j);
	    }
	}
    }
    return 0;
}

int main(){
  // freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int l, r;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    scanf("%d", &a[i][j]);
    l = 0;
    r = inf + 1;
    while(r - l > 1){
	t++;
	if (solve((l + r) / 2))
	    l = (l + r) / 2;
	else
	    r = (l + r) / 2;
    }
    cout << l << endl;

    return 0;
}