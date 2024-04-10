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
	int q;
	scanf("%d",&q);
	while(q--){
		ll n,m,k;
		scanf("%I64d%I64d%I64d",&n,&m,&k);
		if(n < m) swap(n,m);
		if(k < n){
			puts("-1");
			continue;
		}
		if((n - m) % 2 == 0){
			ll std = n;
			if((k - std) % 2 == 0) printf("%I64d\n",k);
			else printf("%I64d\n",k - 2);
		}else{
			ll std = n;
			if((k - std) % 2 == 0) printf("%I64d\n",k - 1);
			else printf("%I64d\n",k - 1);
		}
	}
	return 0;
}