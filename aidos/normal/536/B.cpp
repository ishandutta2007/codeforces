#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int x, z[1000100];
int a[1000100];
int n, m;
char s[1000100];

int b[1000100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
	scanf("%d %d", &x, &m);
	scanf("%s", &s); 
	n = strlen(s);

    for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}

	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	for(int i = 1; i < m; i++){
		if(a[i] - a[i-1] >= n) {
			int cur = 0;
			while(cur < n) {
				b[cur+a[i-1]] = true;
				cur++;
			}
			continue;
		}
		int y = a[i] - a[i-1];
		if(z[y]<n-y){
			printf("0\n");
			return 0;
		}
		for(int j = a[i-1]; j<a[i]; j++)
			b[j] = 1;
	}
	if(m > 0) {
		int cur = 0;
		while(cur < n){
			b[cur+a[m-1]]=1;
			cur++;
		}
	}
	int ans = 1, mod = 1000000007;
//	cout << x << endl;
	for(int i = 0; i < x; i++){
		if(!b[i]) ans=ans * 26ll %mod;
	}
	cout << ans << endl;



	



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}