#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    
    int*a=new int[n];
    int*b=new int[n];
    int*c=new int[n];
    int numpars=0;
    int numb=0;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    bool t=0;
    for(int j=0;j<numb;j++)
            if(b[j]==a[i])
            {
            c[j]++;
            t=1;
            break;
            }
    if(!t)
    c[numb++]=1,b[numb-1]=a[i];
    }
    bool ok=1;
    for(int i=0;i<numb;i++)
    if(b[i]==0)
    continue;
    else if(c[i]>2)
    ok=0;
    else if(c[i]==2)
    numpars++;
    if(ok)
    cout<<numpars<<endl;
    else
    cout<<-1<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}