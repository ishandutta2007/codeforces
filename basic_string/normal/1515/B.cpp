#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n,m;cin>>T;while(T--){
		cin>>n;
		if(n%2==0){m=sqrt(n/2+0.5);
		if(m*m*2==n){puts("YES");goto gg;}}
		if(n%4==0){m=sqrt(n/4+0.5);
		if(m*m*4==n){puts("YES");goto gg;}} 
		puts("NO");
		gg:;
	}
	return 0;
}