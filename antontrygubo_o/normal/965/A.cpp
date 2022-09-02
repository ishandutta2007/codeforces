#include<bits/stdc++.h>
using namespace std;


int main()
{
    int k, n, p, s;
    cin>>k>>n>>s>>p;
    int g = (n+s-1)/s;
    g*=k;
    cout<<(g+p-1)/p;
}