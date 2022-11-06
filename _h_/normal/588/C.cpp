#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	bitset<1010101> num(0);
	int n, w, ans = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&w);
		while(num[w]){
			num[w] = 0;
			++w;
		}
		num[w] = 1;
	}
	rep(i,0,1010101)
		ans += num[i];
	printf("%d\n",ans);
}