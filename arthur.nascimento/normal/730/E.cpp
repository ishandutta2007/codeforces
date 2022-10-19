#include <bits/stdc++.h>
using namespace std;

int score[110];
int add[110];

int ev(int id1,int p1,int id2,int p2){

	if(p1 > p2)
		return 1;
	if(p1 < p2)
		return 0;
	if(id1 < id2)
		return 1;
	return 0;


}

main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d%d",score+i,add+i);
		
	int ans = 0;
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			
			int u1 = 0, u2 = 0;
			
			int A = ev(i,score[i],j,score[j]);
			int B = ev(i,score[i]+add[i],j,score[j]);
			int C = ev(i,score[i]+add[i],j,score[j]+add[j]);
			
			u1 = abs(A-B) + abs(B-C);
			
			B = ev(i,score[i],j,score[j]+add[j]);
			
			u2 = abs(A-B) + abs(B-C);
			
			ans += max(u1,u2);
			
		}
		
	printf("%d\n",ans);
	
}