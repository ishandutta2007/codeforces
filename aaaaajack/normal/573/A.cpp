#include<cstdio>
using namespace std;
int main(){
	int n,pre=0,x;
	bool wrong=false;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		while(x%3==0) x/=3;
		while(x%2==0) x/=2;
		if(pre&&x!=pre) wrong=true;
		pre=x;
	}
	if(wrong) puts("No");
	else puts("Yes");
	return 0;
}