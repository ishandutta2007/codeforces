#include<bits/stdc++.h>
using namespace std;
int S,k,Z[1000011],diff[1000001],l,r;
char s[1000011];
bool ok[1000011];
int main(){
	scanf("%d%d%s",&S,&k,s);
	for(register int i=1;i<S;i++){
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(Z[i]+i<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(Z[i]+i>r)r=Z[i]+i,l=i;
	}
	if(k==1){for(int i=1;i<=S;i++)putchar('1');return 0;}
//	for(int i=0;i<=S;i++)printf("%d:%d\n",i,Z[i]);
	for(register int i=1;i*k<=S;i++){
		if(Z[i]<i*(k-1))continue;
		diff[i*k]++,diff[min(i+Z[i],i*(k+1))+1]--;
	}
	for(register int i=1;i<=S;i++)diff[i]+=diff[i-1],ok[i]=diff[i]>0;
	for(register int i=1;i<=S;i++)putchar('0'+ok[i]);
	return 0;
}