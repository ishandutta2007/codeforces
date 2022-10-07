#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e6;
const int inf = 1e9;

int a[maxn];

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n, cur = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		if (a[i] > a[cur])
			cur = i;
	for (int i = 0; i < n; i++)
		if (i != cur && a[i] > sum)
			sum = a[i];
	cout << cur + 1 << " " << sum << endl;
	
 
    return 0;
}