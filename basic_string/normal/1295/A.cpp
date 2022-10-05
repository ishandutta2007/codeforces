#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n&1)putchar('7'),n-=3;
		while(n)putchar('1'),n-=2;
		putchar(10);
	}
	return 0;
}//w46ke4k5w54kw54k5wkw