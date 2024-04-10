#include<bits/stdc++.h>
using namespace std;
int n;
bool che(int x){
	int tot=0;
	while(x)tot+=x%10,x/=10;
	return !(tot%4);
}
int main(){
	scanf("%d",&n);
	do{
		if(che(n)){
			printf("%d\n",n);
			return 0;
		}	
	}while(n++);
	return 0;
}