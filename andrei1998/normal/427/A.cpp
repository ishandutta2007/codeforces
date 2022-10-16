#include <iostream>

using namespace std;

int main()
{
    int n,i,x,tot=0,rasp=0,ram=0;
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x;

        if(x>=0)
        {
            ram+=x;
            tot+=x;
        }
        else
        {
            if(ram>0)
                ram--;
            else
                rasp++;
        }
    }
    cout<<rasp<<'\n';

    return 0;
}