#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
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
const int maxn = 200100;

int ms[maxn], ps[maxn];
map<int, int> ma;

ll mergesort(int * a, int * b, int l, int r) {
	if(l == r) {return(0);}
	int m = (l + r) / 2;
	ll ret = mergesort(a, b, l, m) + mergesort(a, b, m + 1, r);
	for(int i = l; i <= r; i++) {
		b[i] = a[i];
	}
	int i = l, m1 = m + 1;
	while(l <= m && m1 <= r) {
		if(b[l] > b[m1]) {
			a[i++] = b[m1++];
		} else {
			a[i++] = b[l++];
			ret += m1 - m - 1;
		}
	}
	while(l <= m) {
		a[i++] = b[l++];
		ret += m1 - m - 1;
	}
	while(m1 <= r) {
		a[i++] = b[m1++];
	}

	return(ret);
}

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

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(!ma.count(a)) {ma[a] = a;}
		if(!ma.count(b)) {ma[b] = b;}
		swap(ma[a], ma[b]);
	}
	int m = 0;
	for(map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
		ms[m] = it -> sc;
		ps[m++] = it -> fs;
	}
	ll ans = 0;
	{
		set<int> st;
		for(int i = 0; i < m; i++) {
			while(!st.empty() && ps[i] > *st.begin()) {st.erase(st.begin());}
			ans -= st.size();
			ans += max(0, ms[i] - ps[i]);
			st.insert(ms[i]);
		}
		st.clear();
		for(int i = m - 1; i >= 0; i--) {
			while(!st.empty() && ps[i] < *st.rbegin()) {st.erase(--st.end());}
			ans -= st.size();
			ans += max(0, ps[i] - ms[i]);
			st.insert(ms[i]);
		}
		st.clear();
	}
	{
		ans += mergesort(ms, ps, 0, m - 1);
	}

	cout << ans;

	return(0);
}

// by Kim Andrey