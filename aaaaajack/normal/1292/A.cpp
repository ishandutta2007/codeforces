#include<bits/stdc++.h>
#define N 100100
using namespace std;
int on[N][2];
int main(){
	int n,q,r,c;
	int bk=0;
	scanf("%d%d",&n,&q);
	while(q--){
		scanf("%d%d",&r,&c);
		r--;
		on[c][r]^=1;
		if(on[c][r]) bk+=on[c][r^1]+on[c-1][r^1]+on[c+1][r^1];
		else bk-=on[c][r^1]+on[c-1][r^1]+on[c+1][r^1];
		if(bk)  puts("NO");
		else puts("YES");
	}
	return 0;
}