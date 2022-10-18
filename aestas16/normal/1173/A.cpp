#include <cstdio>
using namespace std;
int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if(x+z>=y&&y+z>=x&&z!=0)puts("?");
    else if(x>y)puts("+");
    else if(y>x)puts("-");
    else if(x==y)puts("0");
    return 0;
}