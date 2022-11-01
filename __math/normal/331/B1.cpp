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

int a[ten(5) + 1];
int d[ten(5) + 1];
int nxt[ten(5) + 1];

int main(){
	
	int n; cin>>n;
	FOR(i,n){
		cin>>a[i];
		d[a[i]] = i;
		nxt[a[i]-1] = i;
	}
	
	int q; cin>>q;
	FOR(i,q){
		int b,x,y; cin>>b>>x>>y;
		if(b == 2){
			x--; y--;
			swap(a[x],a[y]);
			swap(d[a[x]],d[a[y]]);
			//nxt[x-1] = d[x];
			//nxt[y-1] = d[y];
		} else {
			int cnt = 0;
			int pos = INF;
			for(int i = x; i <= y; i++){
				int n_pos = d[i];
				if(pos > n_pos){
					cnt++;
				}
				pos = n_pos;
			}
			cout << cnt << endl;
		}
	}

	return 0;
}