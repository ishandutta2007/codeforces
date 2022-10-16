#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int pr=0,dr=0,sc=0;
    int a,b;
    cin>>a>>b;

    int i;
    for(i=1;i<=6;i++)
    {
        if(abs(i-a)>abs(i-b))
            pr++;
        else if(abs(i-a)==abs(i-b))
            dr++;
        else
            sc++;
    }
    cout<<sc<<' '<<dr<<' '<<pr<<'\n';

    return 0;
}