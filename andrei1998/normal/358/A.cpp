#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int v[1005];
    int n,i,j,stc1,drc1,stc2,drc2;
    cin>>n;
    bool rasp=0;
    for(i=1;i<=n;i++)
        cin>>v[i];

    for(i=2;((i<=n) && (!rasp));i++)
        for(j=i+1;j<=n;j++)
        {
            stc1=v[i-1];
            drc1=v[i];
            stc2=v[j-1];
            drc2=v[j];
            if(stc1>drc1)
                swap(stc1,drc1);
            if(stc2>drc2)
                swap(stc2,drc2);
            if((stc1<stc2) && (drc1<drc2)  && (stc2<drc1))
            {
                rasp=1;
                break;
            }
            else
            if(stc2<stc1 && drc2<drc1 && stc1<drc2)
            {
                rasp=1;
                break;
            }
        }

    if(rasp)
        cout<<"yes\n";
    else
        cout<<"no\n";
    return 0;
}