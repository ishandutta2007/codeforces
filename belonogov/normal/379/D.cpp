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

const int maxn = 1000;
const int inf = 1e9;

pair < long long, int > dp[maxn];
char s1[maxn];
char s2[maxn];



int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int n, m, k, x, st, fn, st2, fn2;
	cin >> k >> x >> n >> m;
	
	for (int mask1 = 0; mask1 < 4; mask1++){
		st = 0;
		fn = n;
		if ((mask1 & (1 << 0)))
			st++;
		if ((mask1 & (1 << 1)))
			fn--;

		for (int i = st; i <= fn; i += 2){
			for (int mask2 = 0; mask2 < 4; mask2++){
				st2 = 0;
				fn2 = m;
				if ((mask2 & (1 << 0)))
					st2++;
				if ((mask2 & (1 << 1)))
					fn2--;
				for (int j = st2; j <= fn2; j += 2){
					dp[0] = mp(i / 2, mask1);
					dp[1] = mp(j / 2, mask2);
					for (int t = 2; t < k; t++)
						dp[t] = mp(dp[t - 1].fr + dp[t - 2].fr + ((dp[t - 2].sc & (1 << 1)) && (dp[t - 1].sc & (1 << 0))), (dp[t - 2].sc & (1 << 0)) | (dp[t - 1].sc & (1 << 1)));
// 					cerr << "dp " << dp[k - 1].fr << endl;
					if (dp[k - 1].fr == x){
						for (int ii = 0; ii < n; ii++)
							s1[ii] = 'X';
						for (int ii = 0; ii < m; ii++)
							s2[ii] = 'X';
						int cur = st;
						for (int ii = 0; ii < i / 2; ii++, cur += 2){
							s1[cur] = 'A';
							s1[cur + 1] = 'C';							
						}
						
						cur = st2;
						for (int ii = 0; ii < j / 2; ii++, cur += 2){
							s2[cur] = 'A';
							s2[cur + 1] = 'C';							
						}
						
						if (st == 1)
							s1[0] = 'C';
						if (st2 == 1)
							s2[0] = 'C';
						if (fn + 1 == n)
							s1[fn] = 'A';
						if (fn2 + 1 == m)
							s2[fn2] = 'A';						
						printf("%s\n", s1);
						printf("%s\n", s2);
						return 0;						
					}
				}
				
			}
			
		}
	}
	printf("Happy new year!\n");	
	
 
    return 0;
}