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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())

int b[4000];
int c[4000];

bool use[1000001];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>b[i];
	memset(c,-1,sizeof(c));

	map<int,int> mp;
	FOR(i,n){
		for(int j = i+1; j < n; j++) if(b[i] == b[j]){
			c[i] = j;
			break;
		}
		if(!use[b[i]]){
			mp[i] = b[i];
		}
		use[b[i]] = true;
	}

	int ans = 1;
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		int tmp = 1;
		for(int i = c[it->first]; i != -1; i = c[i]){
			tmp++;
		}
		ans = max(ans,tmp);
	}

	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		map<int,int>::iterator se = it;
		++se;
		for(; se != mp.end(); ++se){
			int l = it->second;
			int r = se->second;
			int lr[2] = {it->first,se->first};
			int target = 0;
			int tmp = 0;
			while(lr[target] != -1){
				tmp++;
				while(lr[target] != -1 && lr[target] < lr[target^1]){
						lr[target] = c[lr[target]];
					}
				target ^= 1;
			}
			
			ans = max(ans,tmp);
		}
	}

	cout << ans << endl;

    return 0;
}