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
int n,q,a[300100],nex[300100][20],buc[20];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int j=0;j<20;j++)nex[n+1][j]=buc[j]=n+1;
    for(int i=n;i;i--){
        for(int j=0;j<20;j++)nex[i][j]=n+1;
        for(int j=0;j<20;j++)if(a[i]&(1<<j)){
            for(int k=0;k<20;k++)nex[i][k]=min(nex[i][k],nex[buc[j]][k]);
            nex[i][j]=buc[j]=i;
        }
    }
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        bool ok=false;
        for(int j=0;j<20;j++)if(a[y]&(1<<j))ok|=(nex[x][j]<=y);
        puts(ok?"Shi":"Fou");
    }
    return 0;
}