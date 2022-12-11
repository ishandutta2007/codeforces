#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = 20000, mod = int(1e9)  + 7; 

int cnt[N + 2], bp[N+2];
ll ans;
int n,k, mx;

int main () {
	scanf("%d%d",&n,&k);
	for(int i = 1,x; i <= n; i++){
		scanf("%d",&x);
		cnt[x]++;
		mx = max(mx, x);
	}
	for(int i = 0; i <= N; i++){
		bp[i] = __builtin_popcount(i);
	}
	if(k == 0){
		for(int i = 0; i <= mx; i++){
			ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
		}
	}
	else{
		for(int i = 0; i <= mx; i++){
			for(int j = i + 1; j <= mx;j++){
			    int res = (i ^ j);
			    if(bp[res] == k) ans += 1ll * cnt[i] * cnt[j];
			}
		}
	}
	printf("%lld", ans);

return 0;
}