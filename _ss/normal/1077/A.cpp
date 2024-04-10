#include <iostream>

using namespace std;

int main()
{
    int t;
    long long a,b,k;
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>a>>b>>k;
        cout<<(k/2+k%2)*a-(k/2)*b<<endl;
    }
    return 0;
}