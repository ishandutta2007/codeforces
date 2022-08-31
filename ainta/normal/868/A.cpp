#include<cstdio>
#include<algorithm>
using namespace std;
char p[3], q[3];
int n;
int main(){
    int i, ck1 = 0, ck2 = 0;
    scanf("%s",p);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",q);
        if(q[0]==p[1])ck2 |= 1;
        if(q[1]==p[0])ck2 |= 2;
        if(p[0]==q[0]&&p[1]==q[1])ck1=1;
    }
    if(ck1 || ck2==3){
        puts("YES");
    }
    else puts("NO");
}