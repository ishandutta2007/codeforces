/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T;
void mina(){
    int x,y;
    scanf("%d%d",&x,&y);
    if(!x&&!y){puts("0");return;}
    int qwq=sqrt(x*x+y*y)+0.01;
    if(qwq*qwq==x*x+y*y)puts("1");else puts("2");
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}