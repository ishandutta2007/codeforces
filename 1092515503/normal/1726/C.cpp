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
int n,res;
char s[200100];
stack<int>stk;
void mina(){
	scanf("%d%s",&n,s+1),res=1;
	for(int i=1;i<=(n<<1);i++)
		if(s[i]=='(')stk.push(i);
		else{
			if(stk.top()+1!=i)res++;
			stk.pop();
		}
	printf("%d\n",res);
}
int T;
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}