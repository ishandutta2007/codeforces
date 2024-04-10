#include <iostream>
#include <algorithm>
using namespace std;
const int N=2000;

int a[3];
bool c[N],cc[N];
bool funkc()
{
    for(int j=1;j<=a[0];++j)
    {
        bool z=true;
        for(int i=1;i<N;++i)
            c[i]=false;
        for(int i=1;i<N;i+=a[0])
            c[i]=true;
        for(int i=j;i<N;i+=a[1])
            c[i]=true;
        for(int k=1;k<N;++k)
            if(c[k]==false)
            {
                for(int i=k;i<N;i+=a[2])
                    c[i]=true;
                break;
            }
        for(int i=1;i<N;++i)
            if(!c[i])
            {
                z=false;
                break;
            }
        if(z)
            return z;
    }
    return false;
}
int main()
{
    for(int i=0;i<3;++i)
        cin>>a[i];
    do
    {
        if(funkc())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }while(next_permutation(a,a+3));
    cout<<"NO"<<endl;
    return 0;
}