#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define ll long long

int main(int argc, char *argv[])
{
    ll n,ans[40]={0},t,anse=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>t;
            anse+=ans[__builtin_popcount(t)]++;
    }

cout<<anse<<endl;
    return EXIT_SUCCESS;
}