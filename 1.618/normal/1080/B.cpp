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
int query(int pos){
	int ans = pos / 2;
	if(pos & 1) return ans - pos;
	return ans;
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(r) - query(l - 1));
	}
	return 0;
}