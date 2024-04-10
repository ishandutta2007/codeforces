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
int n,a[100100],res;
set<int>s;
void mina(){
	scanf("%d",&n),res=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	s.insert(0);
	for(int i=1,x=0;i<=n;i++){
		x^=a[i];
		if(s.find(x)!=s.end()){res--,x=0,s.clear(),s.insert(0);continue;}
		s.insert(x);
	}
	s.clear();
	printf("%d\n",res);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}
/*
1
4
5 5 5 5
3
1 3 2
2
0 0
3
2 5 7
6
1 2 3 3 2 1
10
27 27 34 32 2 31 23 56 52 4
5
1822 1799 57 23 55
*/