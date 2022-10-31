#include<cstdio>
#include<algorithm>
using namespace std;
char s[10010];
int main(){
    scanf("%s",s);
    int m,l,r,k;
    scanf("%d",&m);
    while(m--){
        scanf("%d%d%d",&l,&r,&k);
        l--;
        k%=(r-l);
        k=(r-l-k)%(r-l);
        rotate(s+l,s+l+k,s+r);
    }
    puts(s);
    return 0;
}