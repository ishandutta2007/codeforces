#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define end fffend
#define y1 qwqwqwqw

using namespace std;

const int maxn = 5e5 + 11;
const ll mod = 998244353;

int a[maxn], end[maxn], lastend[maxn], n, k;

bool check(int val) {
 	if (a[k] - a[1] > val) return 0;
 	if (a[n] - a[1] <= val) return 1;
 	memset(end, 0, sizeof end);
 	memset(lastend, 0, sizeof lastend);
  	int pos = 1;	
 	for (int i = k; i <= n; i++) {
 	     if (i < 2 * k) {
 	      	if (a[i] - a[1] <= val) {
 	      		end[i] = 1;
 	     	}	
 	     } else {
 	      	while (a[i] - a[pos] > val) pos++;
 	      	if (i-k+1>=pos&&lastend[i-k]+1>=pos)
 	      		end[i] = 1;
 	     }
 	     lastend[i] = lastend[i - 1];
 	     if (end[i])
 	     	lastend[i] = i;
 	}
	return end[n];
}

int main() {
     cin >> n >> k;
     for (int i = 1; i <= n; i++)

     	scanf("%I64d", &a[i]);
     sort(a + 1, a + 1 + n);
     if (k + k > n) {
      	cout << a[n] - a[1];
      	return 0;
     }
     int l = -1
     , r = a[n] - a[1] + 1;
     while (r - l > 1) {
      	int mid = (l + r) / 2;
      
      	if (check(mid))
      		r = mid;
      	else
      		l = mid;
     }
     cout << r;
	return 0;
}