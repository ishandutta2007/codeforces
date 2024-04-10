#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x;
    cin>>x;

    if(x.size()<5)
    {
        cout<<"Too weak\n";
        return 0;
    }

    bool ok1=false,ok2=false,ok3=false;

    int i;
    for(i=0;i<x.size();i++)
    {
        if(x[i]>='a' && x[i]<='z')
        {
            ok1=true;
            break;
        }
    }


    for(i=0;i<x.size();i++)
    {
        if(x[i]>='A' && x[i]<='Z')
        {
            ok2=true;
            break;
        }
    }


    for(i=0;i<x.size();i++)
    {
        if(x[i]>='0' && x[i]<='9')
        {
            ok3=true;
            break;
        }
    }

    if(ok1 && ok2 && ok3)
        cout<<"Correct\n";
    else
        cout<<"Too weak\n";

    return 0;
}