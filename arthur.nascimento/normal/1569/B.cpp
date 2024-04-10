#include <bits/stdc++.h>
#define pb push_back 
using namespace std;

char ans[55][55];
int type[55];

main(){

	int nt;
	scanf("%d",&nt);
	
	while(nt--){
		
		int n;
		scanf("%d",&n);
		
		vector<int> t2;
		
		for(int i=0;i<n;i++){
			
			scanf(" %c",type+i);
			
			if(type[i] == '2')
				t2.pb(i);
		
		}
		
		if(t2.size() == 1 || t2.size() == 2){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ans[i][j] = (i == j) ? 'X' : '=';
		
		for(int i=0;i<t2.size();i++)
			ans[t2[i]][t2[(i+1)%t2.size()]] = '+',
			ans[t2[(i+1)%t2.size()]][t2[i]] = '-';
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				printf("%c",ans[i][j]);
			printf("\n");
		}
		
	}
	
}