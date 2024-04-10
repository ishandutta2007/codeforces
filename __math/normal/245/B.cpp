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
#ifdef ONLINE_JUDGE
#define typeof(X) __typeof(X)
#else
#define typeof(X) decltype(X)
#endif
#define FOREACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define sz(c) ((int)(c).size())

int main(){
	string s; cin>>s;
	bool http = false;
	if(s.find("http") == 0) http = true;

	int start_domain = http?4:3;
	int end_domain = (int)s.find("ru",start_domain+1);

	string domain(s.begin() + start_domain,s.begin() + end_domain);
	string context(s.begin() + end_domain + 2,s.end());

	if(sz(context) != 0)
		printf("%s://%s.ru/%s",http?"http":"ftp",domain.c_str(),context.c_str());
	else
		printf("%s://%s.ru",http?"http":"ftp",domain.c_str());

	puts("");

    return 0;
}