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

const int maxn = 3e5 + 2;
const int inf = 1e9;

pair < int, int > a[maxn];
int ans[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, cur = 1;
	cin >> n;
	for (int i = 0; i < n; i++){
		a[i].sc = i;
		scanf("%d", &a[i].fr);		
	}
	sort(a, a + n);
	
	for (int i = 0; i < n; i++){
		ans[a[i].sc] = max(a[i].fr, cur);
		cur = ans[a[i].sc] + 1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
    return 0;
}