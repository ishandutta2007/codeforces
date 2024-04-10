#include <bits/stdc++.h>
using namespace std;

long long n,m,a,b;

int main()
{
    cin>>n>>m>>a>>b;
    cout<<min((n%m)*b,(m-(n%m))*a)<<endl;
    return 0;
}