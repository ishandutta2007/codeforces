#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair

using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
ll gcd(ll x,ll y){
	if(y == 0) return x;
	return gcd(y,x % y);
}
ll m,n,k;
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	ll g = gcd(n * m,k);
	if(k / g > 2){
		puts("NO");
		return 0;
	}
	ll area = n * m * 2 / k;
	ll tmp = m - area % m;
	if(tmp == m) tmp = 0;
	ll y = m;
	ll x = (area + tmp) / m;
	ll b = tmp;
	ll a = 1;
	puts("YES");
	printf("0 0\n");
	printf("%I64d %I64d\n",x,b);
	printf("%I64d %I64d\n",a,y);
	return 0;
}