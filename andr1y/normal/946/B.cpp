#include<iostream>
using namespace std;
long long n,m;
int main()
{
    cin>>n>>m;
    while(n&&m)
        if(n>=2*m)n%=2*m;
        else if(m>=2*n)m%=2*n;
        else break;
    cout<<n<<' '<<m<<endl;
    return 0;
}