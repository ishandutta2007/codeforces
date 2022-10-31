#include<bits/stdc++.h>
using namespace std;
char s[100100],tg[10]="Bulbasr";
int num[10]={1,2,1,1,2,1,1};
int cnt[10];
int main(){
	int ans=1e9;
	scanf("%s",s);
	for(int i=0;s[i];i++){
		for(int j=0;j<7;j++){
			if(s[i]==tg[j]) cnt[j]++;
		}
	}
	for(int i=0;i<7;i++) ans=min(ans,cnt[i]/num[i]);
	printf("%d\n",ans);
	return 0;
}