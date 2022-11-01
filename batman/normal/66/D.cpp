#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll n;
int main()
{
    cin>>n;
    if(n==2)return cout<<-1,0;
    cout<<"15\n6\n";
    for(int i=2;i<n;i++)cout<<10*i<<"\n";
    return 0;
}