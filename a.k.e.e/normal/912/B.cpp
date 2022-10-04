#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

typedef long long ll;

ll n,k;

int main()
{
    cin>>n>>k;
    if(k==1)cout<<n<<endl;
    else
    {
        int high=0;
        for(;(1ll<<high)<=n;high++);
        cout<<(1ll<<high)-1<<endl;
    }
    //system("pause");
    return 0;
}