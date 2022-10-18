#include <cstdio>

int main()
{
    char a,ap;
    ap=getchar();
    bool nf=true;
    int i=0;
    while((a=getchar()) != EOF)
    {
    if(!(a=='0' || a=='1'))
    break;
    if(nf && ap=='0')
    {
         nf=false;
         ap=a;
         continue;
    }
    putchar(ap);
    ap=a;
    }
if(!nf)
putchar(ap);
}