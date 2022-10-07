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

const int maxn = 200;
const int inf = 1e9;

int a[maxn];
vector < int > b[maxn];


bool cmp(int a, int b){
	return a > b;	
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n, cmp);
	for (int ans = 1; ; ans++){
		for (int i = 0; i < ans; i++)
			b[i].clear();
		for (int i = 0; i < n; i++)
			b[i % ans].pb(a[i]);
		bool flag = 1;
		for (int i = 0; i < ans; i++)
			for (int j = (int)b[i].size() - 1; j >= 0; j--)
				flag &= b[i][j] >= (int)b[i].size() - 1 - j;
		if (flag){
			cout << ans << endl;
			return 0;				
		}
	}
    return 0;
}