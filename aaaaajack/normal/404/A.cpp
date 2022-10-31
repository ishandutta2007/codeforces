#include<cstdio>
using namespace std;
int main(){
    int n,i,j;
    char d,c,q;
    bool flag=true;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!i&&!j) q=c=getchar();
            else if(j==1&&i==0) q=d=getchar();
            else q=getchar();
            if((i==j||i+j==n-1)&&q!=c) flag=false;
            if((i!=j&&i+j!=n-1)&&q!=d) flag=false;
        }
        getchar();
    }
    if(d==c) flag=false;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}