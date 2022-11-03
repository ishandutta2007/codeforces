#include <bits/stdc++.h>
using namespace std;
///----------------------defines-----------------------///
#define push_back pb
#define make_pair mp
typedef long long ll;
typedef long double ld;
///--------------------end_of _define------------------///
ll n,k;
///----------------procedures_and_functions------------///

///---------------------program_start-------------------///
int main()
{
    cin>>n>>k;
    for (int i=1;i<=1000000;i++)
        if (i*n%10==0 || i*n%10==k)
    {
        cout<<i;
        return(0);
    }
}