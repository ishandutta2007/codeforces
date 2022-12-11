#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);

vector<pair<int, int> > vc;
int c = 0, x[100100];

multiset<int> st;

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}

	int r = 0;
	for(int i = 0; i < n; i++) {
		while(r < n && (st.empty() || ((x[r] - (*st.begin()) <= k) && ((*st.rbegin()) - x[r] <= k)))) {
			st.insert(x[r]);
			r++;
		}
		int sz = st.size();
		if(sz > c) {
			vc.clear();
			vc.pb(mp(i + 1, r));
			c = sz;
		} else
		if(sz == c) {
			vc.pb(mp(i + 1, r));
		}
		st.erase(st.find(x[i]));
	}

	cout << c << " " << vc.size() << "\n";
	for(int i = 0; i < (int)vc.size(); i++) {
		cout << vc[i].fs << " " << vc[i].sc << "\n";
	}

	return(0);
}

// by Kim Andrey