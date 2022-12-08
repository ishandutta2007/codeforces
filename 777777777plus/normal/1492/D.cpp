#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int a,b,k;

void o(int n,int cnt){
	for(int i=1;i<=cnt;++i)printf("%d",n);
}

int main(){
	cin>>a>>b>>k;
	--b;
	if(!b||!a){
		if(k)puts("No");
		else{
			puts("Yes");
			o(1,b+1);o(0,a);
			printf("\n");
			o(1,b+1);o(0,a);
			printf("\n");
		}
		return 0;
	}
	if(k>a+b-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(k<=a){
		o(1,1+b-1);o(0,a-k);o(1,1);o(0,k);
		printf("\n");
		o(1,1+b-1);o(0,a-k);o(0,k);o(1,1);
		printf("\n");
	}
	else{
		o(1,b+1);o(0,a);
		printf("\n");
		o(1,1+b-(k-a)-1);o(0,1);o(1,k-a);o(0,a-1);o(1,1);
		printf("\n");
	}
}