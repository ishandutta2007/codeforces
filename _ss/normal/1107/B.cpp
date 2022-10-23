#include <iostream>

using namespace std;

int main()
{
    long long k,x;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>k>>x;
        cout<<(k-1)*9+x<<endl;
    }
    return 0;
}