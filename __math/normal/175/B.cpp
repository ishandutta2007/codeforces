#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <string.h>
#include <cassert>

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

using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
const int MODULO = 1000000007;

typedef pair<int,int> Pii;

//BEGIN!!! 

int n;

typedef pair<string,int> P;
vector<P> v;

bool comp(const P&x,const P&y){
	return x.second > y.second;
}

static const char *category[] = {"noob","random","average","hardcore","pro"};

int main()
{
	cin>>n;
	map<string,int> m;
	FOR(i,n){
		string s;
		int j;
		cin >> s >> j;
		if(m.find(s) == m.end()) m[s] = j;
		else m[s] = max(m[s],j);
	}
	FOREACH(it,m) v.push_back(*it);
	sort(v.begin(),v.end(),comp);
	vector<int> points(v.size());
	FOR(i,sz(v)) points[i] = v[i].second;
	cout << v.size() << endl;
	int up = 0;
	int a = 0;
	int last = points[0];
	FOR(i,sz(v)){
		if(last != points[i]){
			up += a;
			a = 1;
			last = points[i];
		} else {
			a++;
		}
		int par = (sz(v) - up) * 100 / sz(v);
		int rank;

		if(par >= 99) rank = 4;
		else if(par >= 90) rank = 3;
		else if(par >= 80) rank = 2;
		else if(par >= 50) rank = 1;
		else rank = 0;

		printf("%s %s\n",v[i].first.c_str(),category[rank]);
	}

	return 0;
}