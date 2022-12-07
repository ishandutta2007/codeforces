#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int k;
int main(){
	scanf("%d",&k);
	if(k > 36) puts("-1");
	else{
		while(k>1){
			printf("8");
			k -= 2;
		}
		if(k) printf("6");
		printf("\n");
	}
	return 0;
}