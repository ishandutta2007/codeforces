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

int x[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	int i = 0;
	while(i + 1 <= n && x[i] < x[i + 1]) {i++;}
	int l = min(i, n);
	while(i + 1 <= n && x[i] > x[i + 1]) {i++;}
	int r = min(i, n);
	while(i + 1 <= n && x[i] < x[i + 1]) {i++;}
	if(i == n) {
		int ll = l, rr = r;
		while(l < r) {swap(x[l++], x[r--]);}
		int i = 0;
		while(i + 1 <= n && x[i] < x[i + 1]) {i++;}
		if(i == n) {
			printf("yes\n%d %d", ll, rr);
		} else {
			printf("no\n");
		}
	} else {
		printf("no\n");
	}
	return(0);
}

// by Kim Andrey