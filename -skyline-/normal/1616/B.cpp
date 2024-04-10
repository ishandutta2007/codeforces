#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n;
char c[100005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf(" %c",c+i);
		if(n==1||c[1]==c[2]){
			printf("%c%c\n",c[1],c[1]);
			continue;
		}
		int k=1;
		while(k<n&&c[k]>=c[k+1])++k;
		for(int i=1;i<=k;++i)printf("%c",c[i]);
		for(int i=k;i;--i)printf("%c",c[i]);
		printf("\n");
	}
    return 0;
}