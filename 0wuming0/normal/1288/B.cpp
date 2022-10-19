#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;b++;
        int c=0;
        for(;b;b/=10)c++;c--;
        cout<<(ll)a*c<<endl;//
    }
}