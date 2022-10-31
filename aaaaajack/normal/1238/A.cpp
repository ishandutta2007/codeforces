#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		if(x>y+1) puts("YES");
		else puts("NO");
	}
	return 0;
}