#include <cstdio>
#include <cmath>
int main(){int n,R,r;scanf("%d%d%d",&n,&R,&r);puts((n>1?(R-r)*sin(3.1415926/n)+1e-7<r:r>R)?"NO":"YES");}