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
const int N = int(3e5), mod = int(1e9)  + 7; 
int n;
ll a[N];
int cnt[N], add[N], c[N], ad[N], pref[N], xx[50],lft[50];
ll p[N];
int ans;

int ispo(ll n){
	int res = 0;
	while(n % 2 == 0) {
		n /= 2;
		res++;
	}
	if(n == 1) return res;
	return -1;
}

void print(){
	puts("-1");
	exit(0);
}

bool check(int k){
	if(cnt[0] < k) return 0;
	for(int j = 0; j <= 41; j++){
		c[j] = cnt[j];
		ad[j] = add[j];
		lft[j] = 0;
	}
	c[0] -= k;
	int res = k;
	for(int j = 1; j <= 41; j++){
		if(c[j] < res){
			lft[j] = res - c[j];
		}
		else lft[j] = 0;
	    res = min(res,c[j]);
	    c[j] -= res;
	}
	for(int j = 41; j >= 0; j--){
		lft[j] += lft[j + 1];
	}
	int potok = 0;
	for(int j = 0; j <= 41; j++){
		potok = min(potok + ad[j], c[j]);
		c[j] -= potok;
	}
	xx[41] = c[41];
	for(int i = 40; i >= 0; i--){
		xx[i] = xx[i + 1] + c[i];
		if(xx[i] > lft[i]) return 0;
	}
	if(k == 0 && xx[41] > 0) return 0;

	return 1;

}

int main () {
	scanf("%d",&n);
	p[0] = 1;
	for(int i = 1; i <= 42; i++) p[i] = p[i - 1] * 2;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		int x = ispo(a[i]);
		if(x != -1){
			cnt[x]++;
		}
		else{
			for(int j = 0; j <= 41; j++){
				if(p[j] <= a[i]) cnt[j]--;
				else{
					add[j]++;
					break;
				}
			}
			ans++;
		}
	}
	for(int i = 0; i <= 41; i++){
		if(cnt[i] < 0) print();
	}
	int res = 0; 
	for(int i = 0; i <= n; i++){
	    if(check(i)){
	    	res++;
	    	printf("%d ", i + ans);
	    }
	}
	if(res == 0) print();
return 0;
}