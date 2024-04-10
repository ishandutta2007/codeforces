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

int n,p, a[N], b[N];

long long sa,sb;

double mn;

bool check(long double x){
	long double t = 0.0, no = 0;
	for(int i = 1; i <= n; i++){
		t += max(no, (a[i] * x - b[i] + 0.0) / (p + 0.0));
	}
	return (t <= x);
}

int main () {
	scanf("%d%d",&n,&p);
	mn = mod;
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&a[i],&b[i]);
		sa += a[i];
	}
	if(sa <= p){
		puts("-1");
		return 0;
	}
	long double l = 0.0, r = mod * 10.0 + 0.0;
	for(int it = 0;it < 150; it++){
		long double mid = (l + r) * 0.5;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.12lf", double(l));

return 0;
}