#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int q,x,y;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(x>y){
			puts("NO");
			continue;
		}
		int k=30;
		for(int i=29;i>=0;--i){
			if(y&(1<<i)){
				if(k>i)k=i+1;
				--k;
				while(k>=0&&!(x&(1<<k)))--k;
				if(k<0) break;
			}
		}
		if(k<0)puts("NO");
		else puts("YES");
	}
    return 0;
}