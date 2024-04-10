#include <iostream>

using namespace std;

struct elem
{
    int a;
    int b;
};

bool operator!=(const elem &a,const elem &b)
{
    return (a.a!=b.a || a.b!=b.b);
}

int main()
{
    int n;
    cin>>n;

    elem ante;
    ante.a=-1;
    ante.b=-1;

    elem curent;
    int ans=0;
    int acum=0;

    for(int i=1;i<=n;i++)
    {
        cin>>curent.a>>curent.b;
        if(curent!=ante){
            if(acum>ans)
                ans=acum;
            acum=1;
        }
        else
            acum++;

        ante=curent;
    }

    if(acum>ans)
        ans=acum;
    cout<<ans<<'\n';

    return 0;
}