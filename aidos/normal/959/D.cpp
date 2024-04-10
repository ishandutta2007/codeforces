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
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;


int n;
int a[200100];

int was[5000200];
int p[5000200];
int lp[5000200];
int good(int x){
	while(x>1){
		if(was[lp[x]]) return 0;
		x/=lp[x];
	}
	return 1;
}
void add(int x){
	while(x>1){
		was[lp[x]] = 1;
		x/=lp[x];
	}
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 2; i < 5000100; i++){
		if(!p[i]){
			lp[i] = i;
			for(int j = i+i; j < 5000100; j += i){
				p[j] = 1;
				if(lp[j] == 0) lp[j] = i;
			}
		}
			
	}
	for(int i = 0; i < n; i++){
		if(good(a[i])){
			add(a[i]);
			continue;
		}
		while(!good(a[i])) ++a[i];
		add(a[i]);
		int k = 2;
		for(int j = i+1; j < n; j++){
			while(!good(k))++k;
			add(k);
			a[j] = k;
		}
		break;
	}
	for(int i = 0; i<n; ++i){
		printf("%d ", a[i]);
	}
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}