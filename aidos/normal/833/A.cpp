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

set < ll > S;
void precalc(){
	for(ll i = 1; i <= 10000; i++){
		S.insert(i*i*i);
	}
}
int a, b;
void solve(){
	scanf("%d%d", &a, &b);
	int g = __gcd(a, b);
	a/=g;
	b/=g;
	if(g % (a * 1ll * b) != 0){
		printf("No\n");
		return;
	}
	g /= a;
	g /= b;
	if(S.count(g)){
		printf("Yes\n");
	}
	else printf("No\n");
}

int main () {
    //cout << "Hello world\n";
    precalc();
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}