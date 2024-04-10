#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sir;
    string rez="";

    cin>>sir;
    int n=sir.size();

    for(int i=0;i<n;i++)
    {
        if(i>1)
            if(sir[i]==sir[i-1] && sir[i]==sir[i-2])
                continue;
        rez+=sir[i];
    }

    sir=rez;
    n=sir.size();

    string afis="";
    for(int i=0;i<n;i++){
        if(afis.size()>2)
            if(sir[i]==afis[afis.size()-1])
                if(afis[afis.size()-3]==afis[afis.size()-2])
                    continue;
        afis+=sir[i];
    }
    cout<<afis<<'\n';

    return 0;
}