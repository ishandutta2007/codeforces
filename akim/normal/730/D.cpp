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
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;

int n, l[N], t[N];
ll ans, r, pref[N], cur,T;

int main () {
	scanf("%d", &n);
	scanf("%I64d", &r);
	for(int i = 1;  i <= n; i++){
		scanf("%d", &l[i]);
		pref[i] = pref[i - 1] + l[i];
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
		if(t[i] < l[i]){
			cout << -1;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		if(cur <= pref[i]){
			ll c = cur - pref[i - 1];
			ll x = t[i] - l[i];
			x = max(x, 0ll);
			x = min(x, l[i] - c);

			cur += x;
			x = l[i] - x - c;
			if(x > 0){
				ll d = (x + r - 1) / r;
				ans += d;
				cur += d * r;
			}
		}
	}
	cout << ans << endl;
	if(ans <= int(1e5)){ 
		cur = 0;
		T = 0;
		for(int i = 1; i <= n; i++){
			if(cur <= pref[i]){
				ll c = cur - pref[i - 1];
				ll x = t[i] - l[i];
				x = max(x, 0ll);
			    x = min(x, l[i] - c);
				cur += x;
				T += 2 * x;
				x = l[i] - x - c;
				if(x > 0){
					ll d = (x + r - 1) / r;
					ans += d;
					cur += d * r;
					ll cx = d;
					while(cx > 0){
						cout << T << " ";
						T += r;
						cx--;
					}
				}
			}
		}	
	}
	

return 0;
}