#include<bits/stdc++.h>
using namespace std;
char s[100];
int main(){
	scanf("%s",s);
	int ans=0;
	for(int i=0;s[i];i++){
		if(isalpha(s[i])){
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') ans++;
		}
		else if((s[i]-'0')%2) ans++;
	}
	printf("%d\n",ans);
	return 0;
}