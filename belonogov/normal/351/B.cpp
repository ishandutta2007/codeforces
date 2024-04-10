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

const int maxn = 1e5;
const int inf = 1e9;

int a[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cnt += a[i] > a[j];
		
	if (cnt % 2 == 0)
		cout << cnt * 2 << endl;
	else
		cout << cnt * 2 - 1 << endl;
	
 
    return 0;
}