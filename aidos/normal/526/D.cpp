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

char s[1000100];
int z[3000100];
int a[3000100];
bool o[2000100];
int n;
int k;
void calc(){
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    scanf("%d %d\n", &n, &k);
    scanf("%s\n", &s);
    if(k == 1){
    	for(int i = 0; i<n; i++){
    		printf("1");
    	}
    	printf("\n");
    	return 0;
    }
    calc();
    for(int i = 1; i <= n; i++){
    	if(i * k > n) break;
    	int j = i;
    	int ok = 1;
    	for(int t = 1; t < k; t++){
    		if(z[j] < i) ok= 0;
    		j+=i;
    	}
    	if(ok) o[j-1] = 1;
    }
    for(int i = 1; i <= n; i++){
    	if(i * (k+1) > n) break;
    	int j = i;
    	int ok = 1;
    	for(int t = 0; t < k; t++){
    		if(z[j] < i) ok= 0;
    		j+=i;
    	}
    	if(ok) o[j-1] = 1;
    }

    for(int i = 1; i<= n; i++){
    	if(i * k > n) break;
    	int j = i;
    	int ok = 1;
    	for(int t = 1; t < k; t++){
    		if(z[j] < i) {
    			ok = 0;
    		}
    		j+=i;
    	}
    	if(ok && j < n){
    		int cur = i;
    		if(cur > z[j]) cur = z[j];
    		a[j]++;
    		a[j+cur]--;
    	}
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
    	sum += a[i];
    	if(sum > 0) o[i] = 1;
    }
    for(int i = 0;i <n; i++){
    	printf("%d", o[i]);
    }
	printf("\n");







    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}