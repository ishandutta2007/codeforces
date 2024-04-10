#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
    cin>>a>>b>>c;
    cout<<max(max(max(a+b+c,a*b+c),max(a+b*c,a*b*c)),max((a+b)*c,a*(b+c)));
}