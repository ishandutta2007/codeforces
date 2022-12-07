#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r,d;
		scanf("%d%d%d",&l,&r,&d);
		if(d < l) printf("%d\n",d);
		else if(r % d == 0) printf("%d\n",r + d);
		else printf("%d\n",r - r % d + d);
	}
	return 0;
}