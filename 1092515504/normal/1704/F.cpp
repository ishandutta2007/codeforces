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
typedef long long ll;
int T,n;
char s[500100];
int sg[500100];
void mina(){
	scanf("%d%s",&n,s+1);
	if(count(s+1,s+n+1,'R')<count(s+1,s+n+1,'B')){puts("Bob");return;}
	if(count(s+1,s+n+1,'R')>count(s+1,s+n+1,'B')){puts("Alice");return;}
	// puts("Tie");
	int SG=0;
	for(int i=1,j;i<=n;i=j+1){
		for(j=i;j<n&&s[j]!=s[j+1];j++);
		int k=j-i+1;
		SG^=sg[k];
	}
	puts(SG?"Alice":"Bob");
}
int main(){
	n=1000;
	for(int i=2;i<=n;i++){
		bool occ[1010];memset(occ,false,sizeof(occ));
		for(int j=1;j+1<=i;j++)occ[sg[j-1]^sg[i-j-1]]=true;
		while(occ[sg[i]])sg[i]++;
	}
	for(int i=1001;i<=500000;i++)sg[i]=sg[i-34];
	// for(int i=1;i<=n;i++)printf("%d ",sg[i]);
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
12 8
25 3 3 17 8 6 1 16 15 25 17 23
*/