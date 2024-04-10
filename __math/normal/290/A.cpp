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
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

string s[] = {"Washington",
	"Adams",
	"Jefferson",
	"Madison", 
	"Monroe",
	"Adams",
	"Jackson",
	"Van Buren",
	"Harrison",
	"Tyler",
	"Polk",
	"Taylor",
	"Fillmore",
	"Pierce",
	"Buchanan",
	"Lincoln",
	"Johnson",
	"Grant",
	"Hayes",
	"Garfield",
	"Arthur",
	"Cleveland",
	"Harrison",
	"Cleveland",
	"McKinley",
	"Roosevelt",
	"Taft",
	"Wilson",
	"Harding",
	"Coolidge",
	"Hoover",
	"Roosevelt",
	"Truman",
	"Eisenhower",
	"Kennedy",
	"Johnson",
	"Nixon",
	"Ford",
	"Carter",
	"Reagan",
	"Bush",
	"Clinton" };

int main(){
	int n; cin >> n;
	cout << s[n-1] << endl;

	return 0;
}