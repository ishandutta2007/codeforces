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
ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b,a % b);
}
int main(){
	ll a,b,x,y;
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);
	ll g = gcd(x,y);
	x /= g,y /= g;
	printf("%I64d\n",min(a / x,b / y));
	return 0;
}