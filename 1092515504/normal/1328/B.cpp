#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,k;
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		for(int i=2;i<=n;i++){
			if(k>i-1){k-=i-1;continue;}
			for(int j=n;j>i;j--)putchar('a');
			putchar('b');
			for(int j=i-1;j>k;j--)putchar('a');
			putchar('b');
			for(int j=k-1;j>=1;j--)putchar('a');
			break;
		}
		putchar('\n');
	}
	return 0;
}