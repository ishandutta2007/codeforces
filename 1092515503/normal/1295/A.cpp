#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n&1)putchar('7'),n-=3;
		while(n)putchar('1'),n-=2;
		puts("");
	}
	return 0;
}