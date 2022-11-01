#include <cstdio>
#include <cmath>
#define EPS 1e-10

using namespace std;



int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int c1, c2, i, j, x, k, dist, xdist;
    scanf("%d%d", &c1, &c2);
    dist=c1*c1+c2*c2;
    for(i=1;i<c1;i++)
    {
        x=sqrt(c1*c1-i*i);
        if(x*x+i*i!=c1*c1) continue;
        for(j=1;j<c2;j++)
        {
            k=sqrt(c2*c2-j*j);
            if(k*k+j*j!=c2*c2) continue;
            if(k==x) continue;
            xdist=(i+j)*(i+j)+(k-x)*(k-x);
            if(dist==xdist)
            {
                printf("YES\n%d %d\n0 0\n%d %d\n", i, x, -j, k);
                return 0;
            }
        }
    }
    printf("NO\n");
}