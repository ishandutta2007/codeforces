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
int n;

int main(){
	cin >> n;
	string trw;
	int raise_i = -1;
	string s;
	getline(cin,s);
		stack<int> stk;
	for(int i = 0; i < n; i++){
		getline(cin,s);
		replace(s.begin(),s.end(),'(',' ');
		replace(s.begin(),s.end(),')',' ');
		replace(s.begin(),s.end(),',',' ');
		istringstream iss(s);

		string cmd; iss >> cmd;
		if(cmd == "try"){
			stk.push(i);
		} else if(cmd == "catch") {
			int try_i = stk.top(); stk.pop();
			if(raise_i < try_i) continue;
			string catch_name; iss>>catch_name;

			if(trw == catch_name){
				string ans; getline(iss,ans);
				int fst = ans.find_first_of('"') + 1;
				int lst = ans.find_last_of('"');
				cout << string(ans.begin() + fst,ans.begin() + lst) << endl;
				return 0;
			}
		} else if(cmd == "throw"){
			iss >> trw;
			raise_i = i;
		}
	}

	cout << "Unhandled Exception" << endl;

	return 0;
}