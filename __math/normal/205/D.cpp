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

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

int n;
int l[100000],r[100000];

int main(){
	cin>>n;
	map<int,int> front;
	map<int,int> all;
	for(int i =0; i < n; i++) cin>>l[i]>>r[i];
	for(int i =0; i < n; i++){
		front[l[i]]++;
		if(l[i] == r[i]){
			all[l[i]]++;
		} else {
			all[l[i]]++;
			all[r[i]]++;
		}
	}

	int c = (n+1)/2;
	int ans = (int)1e8;
	for(map<int,int>::iterator it = all.begin(); it != all.end(); ++it){
		if((*it).second < c) continue;
		int f = front[(*it).first];
		ans = min(ans,max(0,c - f));
	}

	if(ans == (int)1e8) puts("-1");
	else cout << ans << endl;

	return 0;
}