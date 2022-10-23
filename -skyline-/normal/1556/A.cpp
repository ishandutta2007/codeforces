#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		int o=x+y;
		if(o&1)printf("-1\n");
		else if(x==0&&y==0)printf("0\n");
		else if(x==y)printf("1\n");
		else printf("2\n");
	}
    return 0;
}