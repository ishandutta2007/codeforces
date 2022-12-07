#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll a,b,n,m;
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&a,&b);
	ll r = n % m;
	printf("%I64d\n",min(r * b,(m - r) * a));
	return 0;
}