#include<bits/stdc++.h>
using namespace std;
char s[1000011];
int Z[1000011],l,r,S,cnt[1000011],len;
int main(){
	scanf("%s",s),S=strlen(s);
	for(int i=1;i<S;i++){
		if(i<=r)Z[i]=min(Z[i-l],r-i);
		while(Z[i]+i<S&&s[Z[i]]==s[Z[i]+i])Z[i]++;
		if(r<i+Z[i])l=i,r=i+Z[i];
	}
//	for(int i=1;i<S;i++)printf("%d ",Z[i]);puts("");
	for(int i=1;i<S;i++)cnt[0]++,cnt[Z[i]+1]--;
	for(int i=1;i<=S;i++)cnt[i]+=cnt[i-1];
	for(int i=1;i<S;i++)if(i+Z[i]>=S&&cnt[Z[i]]>=2){len=Z[i];break;}
	if(!len)puts("Just a legend");
	else for(int i=0;i<len;i++)putchar(s[i]);
	return 0;
}