#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int k=1;
	while(1){
		if(k*3>=n+1){
			printf("%d\n",k*2-1);
			for(int i=1;i<=k;++i)printf("%d %d\n",i,k+1-i);
			for(int i=1;i<=k-1;++i)printf("%d %d\n",n+1-i,n-k+1+i);
			break;
		}
		
		if(k*3>=n){
			printf("%d\n",k*2);
			for(int i=1;i<=k;++i)printf("%d %d\n",i,k+1-i);
			for(int i=1;i<=k-1;++i)printf("%d %d\n",n+1-i,n-k+1+i);
			printf("%d %d\n",k+1,k+1);
			break;
		}
		++k;
	}
    return 0;
}