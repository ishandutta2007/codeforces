#include<cstdio>
using namespace std;
int a,b,c,t,rs;
double ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        ans=(b-a+c)/2.0;
        if(ans<0)printf("%d\n",c+1);
        else if(ans==0)printf("%d\n",c);
        else if(ans>=c)printf("%d\n",0);
        else if(ans<c){rs=ans*10;rs/=10;printf("%d\n",c-rs);}
    }
    return 0;
}