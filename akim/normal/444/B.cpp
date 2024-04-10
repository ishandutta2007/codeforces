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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

long long x;
int a[100100], b[100100], p[100100], e[100100], k;

int nx() {x = (x * 37 + 10007) % 1000000007; return(x);}
set<int> st;
set<int>::iterator it;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n, d;
	scanf("%d%d%I64d", &n, &d, &x);
	for(int i = 0; i < n; i++) {a[i] = i; swap(a[i], a[nx() % (i + 1)]);}
	for(int i = 0; i < n; i++) {b[i] = ((i < d) ? (1) : (0)); swap(b[i], b[nx() % (i + 1)]);}

	for(int i = 0; i < n; i++) {
		st.insert(-a[i]);
		p[a[i]] = i;
		if(b[i]) e[k++] = i;
		if(k < 400) {
			int ans = -1;
			for(int f = 0; f < k; f++) {
				if(ans < a[i - e[f]]) {
					ans = a[i - e[f]];
				}
			}
			printf("%d\n", ans + 1);
		} else {
			for(it = st.begin(); it != st.end(); it++) {
				if(b[i - p[-(*it)]]) {
					printf("%d\n", -(*it) + 1);
					break;
				}
			}
		}
	}

	return(0);
}

// by Kim Andrey