//Will it FST?
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

int main(){
	ll n,k;
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",(k + n - 1) / n);
	return 0;
}