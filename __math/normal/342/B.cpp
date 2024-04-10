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
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }



int t[ten(5)],l[ten(5)],r[ten(5)];

int main(){
	int n,m,s,f;
	cin>>n>>m>>s>>f;
	s--; f--;
	FOR(i,m){
		cin>>t[i]>>l[i]>>r[i];
		l[i]--;
	}

	string ans;
	int cur = s;
	int t_cur = 0;
	int turn = 0;
	while(turn++,cur != f){
		int nxt;
		if(cur > f) nxt = cur-1;
		else nxt = cur + 1;

		if(t_cur < m && t[t_cur] == turn){
			if(
				(l[t_cur] <= cur && cur < r[t_cur]) ||
				(l[t_cur] <= nxt && nxt < r[t_cur])
				)
			{
				nxt = cur;
			}
			t_cur++;
		}

		if(nxt == cur) ans.push_back('X');
		else if(nxt > cur) ans.push_back('R');
		else ans.push_back('L');

		cur = nxt;
	}

	cout << ans << endl;

	return 0;
}