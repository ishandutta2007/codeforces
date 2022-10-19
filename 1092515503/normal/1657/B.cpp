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
typedef long long ll;
int T,n,B,x,y;
ll res;
void mina(){
    scanf("%d%d%d%d",&n,&B,&x,&y);
    for(int i=1,a=0;i<=n;i++){
        if(a+x<=B)a+=x;
        else a-=y;
        // printf("%d:%d\n",i,a);
        res+=a;
    }
    printf("%lld\n",res),res=0;
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}