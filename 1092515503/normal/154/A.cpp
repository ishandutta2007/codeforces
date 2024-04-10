#include<bits/stdc++.h>
using namespace std;
char s[100010],p[10];
int _1,ans,S,t1,t2;
int main(){
	scanf("%s%d",s,&_1),S=strlen(s);
	while(_1--){
		scanf("%s",p);
		for(int i=0;i<S;i++){
			if(s[i]==p[0]){t1++;continue;}
			if(s[i]==p[1]){t2++;continue;}
			ans+=min(t1,t2),t1=t2=0;
		}
		ans+=min(t1,t2),t1=t2=0;
	}
	printf("%d",ans);
	return 0;
}