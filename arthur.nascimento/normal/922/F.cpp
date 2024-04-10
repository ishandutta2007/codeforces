#include <bits/stdc++.h>
using namespace std;
#define maxn 300300

int d[maxn];
int block[maxn];

bool pr(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i == 0)
			return 0;
	return 1;
}

main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	if(k == 6){
		if(n < 6)
			printf("No\n");
		else
			printf("Yes\n5\n 1 2 4 5 6\n");
		return 0;
	}
	
	if(k == 15){
	    if(n < 10) 
	        printf("No\n");
	    else
	        printf("Yes\n9\n1 2 3 4 6 7 8 9 10\n");
	   return 0;
	}
	
	if(k == 20){
		if(n < 12)
			printf("No\n");
		else
			printf("Yes\n11\n1 2 3 4 5 6 7 8 9 11 12\n");
		return 0;
	}
	
	if(k == 31){
	    if(n < 16)
	        printf("No\n");
	    else
	        printf("Yes\n15\n1 2 3 4 6 7 8 9 10 11 12 13 14 15 16\n");
	    return 0;
	}
	
	for(int i=1;i<=n;i++)
		for(int j=2*i;j<=n;j+=i)
			d[j]++;
			
	int s = 0;
	for(int i=1;i<=n;i++)
		s += d[i];

	if(s < k){
		printf("No\n");
		return 0;
	}
		
	int u = n;
	while(s-d[u] >= k){
		s -= d[u];
		u--;
	}

	
	vector<int> ans;
	
	for(int i=1;i<=u;i++){
		if(i > 2 && 2*i > u && s > k && pr(i)){
			s--;
		}
		else if(i > 2 && 3*i > u && 2*i <= u && s-3 > k && pr(i)){
			s -= 4;
			block[2*i] = 1;
		}
		else if(!block[i])
			ans.push_back(i);
	}
	
	printf("Yes\n%d\n",ans.size());
	
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
		
}