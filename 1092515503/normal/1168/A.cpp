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
int n,m,a[300100];
bool che(int mid){
    int mn=0;
    for(int i=1;i<=n;i++){
        if(a[i]+mid>=m){
            if(mn<=(a[i]+mid)%m)continue;
            mn=max(mn,a[i]);
        }else{
            if(mn>a[i]+mid)return false;
            mn=max(mn,a[i]);
        }
    }
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l=0,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(che(mid))r=mid;else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}