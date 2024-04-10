#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=20;i>=0;i--){
		if(n&(1<<i)) printf("%d ",i+1);
	}
	return 0;
}