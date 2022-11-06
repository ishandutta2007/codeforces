#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <time.h>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(stt) for (int i = 0; i < stt; ++i)
#define foj(stt) for (int j = 0; j < stt; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

int main() {
    // openfiles("test");
    int n;
    sci(n);
    vei a(n);
    foi(n) sci(a[i]);
    ll l = (*max_element(all(a))) - 1, r = 1e13, m;
    while (r - l > 1) {
    	m = (r + l) >> 1;
    	ll s = 0;
    	foi(n) {
    		s += m - a[i];
    	}
    	if (s >= m) {
    		r = m;
    	} else {
    		l = m;
    	}
    }
    cout << r;

    
    return 0;
}