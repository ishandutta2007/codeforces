#include <cstdio>
using namespace std;
int main(){
    long long n,m,a;
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    printf("%I64d",(n%a?n/a+1:n/a)*(m%a?m/a+1:m/a));
    return 0;
}