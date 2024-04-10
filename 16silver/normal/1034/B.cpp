#include <cstdio>
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    if(n>m){
        long long t = n;
        n=m;
        m=t;
    }
    if(n>2LL){
        if(n%2LL==1LL && m%2LL==1LL) printf("%lld",n*m-1LL);
        else printf("%lld",n*m);
    }
    else if(n==2LL){
        if(m==2LL) printf("0");
        else if(m==3LL) printf("4");
        else if(m==7LL) printf("12");
        else printf("%lld",2LL*m);
    }
    else{
        switch(m%6){
            case 0:
            case 1:
            case 2:
            case 3: printf("%lld",(m/6LL)*6LL); break;
            case 4: printf("%lld",(m/6LL)*6LL+2LL); break;
            case 5: printf("%lld",(m/6LL)*6LL+4LL); break;
        }
    }
}