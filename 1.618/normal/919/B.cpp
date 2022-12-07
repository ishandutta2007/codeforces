#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
int k,i=19;
bool jud(int x){
	int sum = 0;
	while(x){
		int a = x%10;
		x /= 10;
		sum += a;
		if(sum > 10) return 0;
	}
	return sum == 10;
}
int main(){

	scanf("%d",&k);

	while(k){
		while(!jud(i)) i++;
		k--;
		i++;
	}
	
	printf("%d\n",i-1);
	return 0;
}