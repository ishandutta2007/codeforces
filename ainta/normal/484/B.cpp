#include<stdio.h>
#include<algorithm>
using namespace std;
int n, S[2010000], Res, be, ed, mid;
bool Pos(int g){
    int i, j;
    for(i=g+1;i<=1000000;i++){
        if(!(S[i]-S[i-1]))continue;
        for(j=i;j+g<=1000000;j+=i){
            if(S[j+i-1]-S[j+g-1])return true;
        }
    }
    return false;
}
int main(){
    int i, a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        S[a]++;
    }
    for(i=1;i<=2000000;i++)S[i]+=S[i-1];
    be = 1, ed = 1000000;
    while(be<=ed){
        mid = (be+ed)/2;
        if(Pos(mid)){
            Res = mid;
            be = mid + 1;
        }
        else ed = mid - 1;
    }
    printf("%d\n",Res);
}