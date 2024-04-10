#include <iostream>

using namespace std;
long long n,m,k,x,m1=0,m2=0;
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x>m1)
        {
            m2=m1;
            m1=x;
        }
        else if (x>m2) m2=x;
    }
    cout<<(m/(k+1))*(k*m1+m2)+(m%(k+1))*m1;
    return 0;
}