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
int n,p[200100],tot,num;
bool b[200100],vis[200100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),tot+=b[i];
	for(int i=1;i<=n;i++)if(!vis[i]){
		num++;
		for(int j=i;!vis[j];j=p[j])vis[j]=true;
	}
	printf("%d\n",(num==1?0:num)+!(tot&1));
	return 0;
}