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
char s[300100];
int n;
long long res;
int main(){
    /*for(int i=0;i<(1<<10);i++){
        bool ok=false;
        for(int j=0;j<10;j++)for(int k=0;j+(k<<1)<10;k++)
            if(((i>>j)&1)==((i>>j+k)&1)&&((i>>j+k)&1)==((i>>j+(k<<1))&1))
                ok=true;
        if(!ok)printf("%d\n",i);
    }*/
    scanf("%s",s+1),n=strlen(s+1);
    for(int i=1,j=0;i<=n;i++){
        for(int k=1;i-(k<<1)>j;k++)if(s[i]==s[i-k]&&s[i-k]==s[i-(k<<1)]){j=i-(k<<1);break;}
        res+=j;
    }
    printf("%lld\n",res);
    return 0;
}