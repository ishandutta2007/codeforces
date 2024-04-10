#include <cstdio>
#include <algorithm>
using namespace std;
char r[303030];
int main(){
    int n,i,s=1;
    long long x,y,c=0;
    scanf("%d%lld%lld",&n,&x,&y);
    scanf("%s",r);
    for(i=0;i<n;i++){
        if(r[i]=='0'){
            if(s==1) c++;
            s=0;
        }
        else{
            s=1;
        }
    }
    if(c==0) printf("0");
    else{
        printf("%lld",min((c-1)*x+y,c*y));
    }
}