#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int main(){
	int n,a,b,c,d;
	scanf("%d",&n),a=1,b=0;
	while(n--){
		c=b,d=(a*3ll+b*2ll)%P;
		a=c,b=d;
	}
	cout<<a;
	return 0;
}