#include <bits/stdc++.h>
using namespace std;
#define debug 
#define maxn 400400
int a[maxn];
int b[maxn];
int c[maxn];
int pos[maxn];

int main(){

	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",a+i), pos[a[i]] = -1;
	for(int i=0;i<n;i++)
		scanf("%d",b+i), pos[b[i]] = i;

	int ib = -1;
	
	for(int i=0;i<n;i++)
		if(b[i] == 1) ib = i;

	int good = 1;
	int ans = 0;
	if(ib+1){
		
		for(int j=ib+1;j<n;j++)
			if(b[j] != b[j-1] + 1)
				good = 0;
				
		for(int j=1+b[n-1],x=-1;j<=n;j++,x++){
			debug("check is pos[%d] >= %d\n",j,x);
			if(pos[j] > x)
				good = 0;
			
		}
		
		if(good){
			printf("%d\n",ib);
			return 0;
		}
		
		for(int j=0;j<=ib;j++){
			pos[b[j]] = -1;
			debug("move %d to hand\n",b[j]);
		}
		
		for(int j=ib+1;j<ib+n+1;j++)
			c[j-ib-1] = b[j];
			
		for(int j=0;j<n;j++){
			b[j] = c[j];
			debug("%d ",b[j]);
		}
		debug("\n");		
		ans += ib+1;
	}
	
	int add = 0;
	for(int i=0;i<n;i++)
		if(b[i] > 0){
			add = max(add,i+2-b[i]);
		}
	
	printf("%d\n",ans+add+n);
}