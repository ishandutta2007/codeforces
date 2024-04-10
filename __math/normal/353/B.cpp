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

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }


int main(){
	int n;
	cin>>n;
	int a[100] = {};
	vector<int> b(2*n);
	FOR(i,2*n){
		cin>>b[i];
		a[b[i]]++;
	}

	vector<int> c1,c2;
	FOR(i,100) if(a[i]){
		if(a[i] == 1) c1.push_back(i);
		else c2.push_back(i);
	}

	int left = sz(c2),right = sz(c2);
	left += sz(c1) / 2;
	right += sz(c1) - sz(c1) / 2;

	cout << left * right << endl;

	int l[100] = {};
	FOR(i,sz(c1) / 2) l[c1[i]]++;
	FOR(i,sz(c2)) l[c2[i]]++;
	FOR(i,100){
		a[i] = max(0,a[i] - 2);
		while(left < n && a[i]){
			l[i]++;
			left++;
			a[i]--;
		}
	}

	vector<int> ans(2*n);
	FOR(i,2*n){
		if(l[b[i]]){
			ans[i] = 1;
			l[b[i]]--;
		} else {
			ans[i] = 2;
		}
	}

	FOR(i,2*n){
		printf("%d%c",ans[i],i==2*n-1?'\n':' ');
	}

	return 0;
}