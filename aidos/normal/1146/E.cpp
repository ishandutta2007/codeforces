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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, q;
int b[200100];
int a[200100];
int d[200100];
int B[200100];
int A[200100];
int sz = 400;
int BB[200200];
int AA[200200];
int C[200200];
void upd(int x){
	if(x < 0) {
		b[abs(x)] = 1;
	}
	else a[x] = 1;
}

int ok(int l, int r, int x){
	return l <= x && x <= r;
}
int ok2(int a, int b, char c){
	if(c == '>') return a > b;
	return a < b;
}

void norm(int st) {
	for(int i = 0; i < sz; i++) AA[i] = BB[i] = 0;
	if(A[st/sz]) {
		for(int i = 0; i < sz; i++) C[i+st] ^= 1;
		for(int i = 0; i < sz; i++) if(a[i + st]) BB[i] = 1;
	}else {
		for(int i = 0; i < sz; i++) if(a[i + st]) AA[i] = 1;
	}
	
	if(B[st/sz]) {
		for(int i = 0; i < sz; i++) if(b[i + st]) AA[i] = 1;
	}else {
		for(int i = 0; i < sz; i++) if(b[i + st]) BB[i] = 1;
	}
	A[st/sz] = 0;
	B[st/sz] = 0;
	for(int i = 0; i < sz; i++) {
		a[i+st] = AA[i];
		b[i+st] = BB[i];
	}
}
void calc(int st, int x, char c){
	norm(st);
	for(int i = 0; i < sz; i++){
		if(ok2(i + st, x, c) && ok2(-i-st, x, c)) {	
			swap(a[i+st],b[i+st]);
			C[i + st] ^= 1;
		}
		else if(ok2(i + st, x, c)){
			b[i + st] = b[i + st] | a[i + st];
			a[i + st] = 0;
		}else if(ok2(-i - st, x, c)){
			a[i + st] = b[i + st] | a[i + st];
			b[i + st] = 0;
		}
	}
}

void calc2(int st, int x, int c){
	if(ok2(st, x, c) && ok2(-st, x, c)) {
		A[st/sz] ^= 1;
		B[st/sz] ^= 1;
	}
	else if(ok2(st, x, c)){
		if(!A[st/sz]) A[st/sz] = 1;
		if(B[st/sz]) B[st/sz] = 0;
	}else if(ok2(-st, x, c)){
		if(A[st/sz]) A[st/sz] = 0;
		if(!B[st/sz]) B[st/sz] = 1;
	}
}

int get(int x){
	int t = abs(x);
	if(a[t] && b[t]) {
		if(C[t]) printf("%d ", -x);
		else printf("%d ", x);
	}else if(a[t]) {
		printf("%d ", t);
	}else printf("%d ", -t);
}
void solve(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%d", &d[i]);
		upd(d[i]);
	}
	
	int mx = 100100;
	
	char tmp[11];
	for(int i = 0; i < q; i++){
		char c;
		int x;
		scanf("%s%d", tmp, &x);
		c = tmp[0];
		for(int t = 0; t <= mx; t += sz) {
			if(ok(t, t + sz - 1, x)||ok(-(t+sz-1), -t, x)) {
				calc(t, x, c);	
			}else {
				calc2(t, x, c);
			}
		}
	}
	for(int i = 0; i <= mx; i+=sz) norm(i);
	for(int i = 0; i < n; i++){
		get(d[i]);
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