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

ll L[111], R[111], SHIFT[111], SHIFTVAL[111]; 
int sz = 1;

void upd1(){
	ll x, k;
	scanf("%lld%lld", &x, &k);
	int g = 1;
	while(R[g] < x) g++;
	SHIFTVAL[g] -= k;
	SHIFTVAL[g] %= (R[g] - L[g]+1);	
	SHIFTVAL[g] += (R[g] - L[g]+1);
	SHIFTVAL[g] %= (R[g] - L[g]+1);	
}

void upd2(){
	ll x, k;
	scanf("%lld%lld", &x, &k);
	int g = 1;
	while(R[g] < x) g++;
	while(g <= sz){
		SHIFTVAL[g] -= k;
		SHIFTVAL[g] %= (R[g] - L[g]+1);	
		SHIFTVAL[g] += (R[g] - L[g]+1);
		SHIFTVAL[g] %= (R[g] - L[g]+1);	
		k = (k * 2) % (R[sz] - L[sz]+1);
		g++;
	}
}
void get(){
	ll x;
	scanf("%lld", &x);
	int g = 1;
	while(R[g] < x) g++;
	ll pos = x - L[g];
	pos -= SHIFTVAL[g];
	if(pos < 0) pos += R[g] - L[g]+1;
	while(g>0){
		ll d = (SHIFTVAL[g] + pos) % (R[g] - L[g]+1);
		
		printf("%lld", d + L[g]);
		pos /= 2;
		if(g>1)
			printf(" ");
		g--;
	}
	printf("\n");
	
}
void solve(){
	L[1] = R[1] = 1;

	while(R[sz] <= (ll)2e18) {
		R[sz+1] = R[sz] * 2 + 1;
		L[sz+1] = R[sz]+1;
		sz++;
	}
	int q;
	scanf("%d", &q);
	for(int i = 0, ty; i < q; i++){
		scanf("%d", &ty);
		if(ty == 1){
			upd1();
		}else if(ty == 2){
			upd2();
		}else{
			get();
		}
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