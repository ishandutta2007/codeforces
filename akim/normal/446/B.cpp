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

#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

long long a[1010], b[1010], oa[1000100], ob[1000100];
priority_queue<long long> qa, qb;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	long long n, m, k, p, i, f;
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &p);
	for(i = 0; i < n; i++) {
		for(f = 0; f < m; f++) {
			int c;
			scanf("%d", &c);
			a[i] += c;
			b[f] += c;
		}
	}
	for(i = 0; i < n; i++) {qa.push(a[i]);}
	for(f = 0; f < m; f++) {qb.push(b[f]);}
	for(i = 1; i <= k; i++) {
		long long q = qa.top();
		qa.pop();
		qa.push(q - p * m);
		oa[i] = oa[i - 1] + q;
		q = qb.top();
		qb.pop();
		qb.push(q - p * n);
		ob[i] = ob[i - 1] + q;
	}

	long long ans = oa[0] + ob[k];
	for(i = 0; i <= k; i++) {
		ans = max(ans, oa[i] + ob[k - i] - i * (k - i) * p);
	}
	
	printf("%I64d", ans);

	return(0);
}

// by Kim Andrey