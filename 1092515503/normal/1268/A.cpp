/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200100];
int main(){
	scanf("%d%d%s",&n,&m,s);
	bool ok=true;
	for(int j=m;j<n;j++)
		if(s[j]==s[j-m])continue;
		else{ok=(s[j]<s[j-m]);break;}
	if(ok){
		for(int j=m;j<n;j++)s[j]=s[j-m];
		printf("%d\n",n);
		printf("%s\n",s);
		return 0;
	}
	for(int j=m-1;;j--){
		if(j<0){s[0]='1',n++;break;}
		if(s[j]!='9'){s[j]++;break;}
		s[j]='0';
	}
	printf("%d\n",n);
	for(int j=m;j<n;j++)s[j]=s[j-m];
	printf("%s\n",s);
	return 0;
}