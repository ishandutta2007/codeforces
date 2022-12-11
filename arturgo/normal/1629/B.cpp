#include<cstdio>
#include<algorithm>

using namespace std;


int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		if(l==r){
			if(l!=1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			int n=r/2-(l-1)/2;
			if((r+1-l)-n<=k){
				printf("YES\n");
			}
			else
				printf("NO\n");
		}
	}
}