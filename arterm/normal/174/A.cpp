#include <cstdio>
#include <algorithm>

#define M 200

using namespace std;

int main()
{
    long n;
    double a[M],b,m=-1,s;
    scanf("%d%lf",&n,&b);
    s=b;
    for (long i=0; i<n; ++i){
        scanf("%lf",&a[i]);
        s+=a[i];
        m=max(m,a[i]);
    }
    if (m>s/n)
    printf("-1");
    else
    for (long i=0; i<n; ++i)
    printf("%.6lf\n",s/n-a[i]);
    return 0;
}