#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
mt19937 r(time(NULL));
int n;
int main(){
	scanf("%d",&n);
	if(n<=100){
		for(int i=1;i<=n;++i){
			printf("? %d\n",i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			if(x==1){
				printf("! %d\n",i);
				return 0;
			}
		}
		return 0;
	}
	int l=1,r=n+1;
	while(r>l+1){
		int m=(l+r)/2;
		int x,y;
		printf("? %d\n",m-1);
		fflush(stdout);
		scanf("%d",&x);
		printf("? %d\n",m);
		fflush(stdout);
		scanf("%d",&y);
		if(x<y)r=m;
		else l=m;
	}
	printf("! %d\n",l);
    return 0;
}