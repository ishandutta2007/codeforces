#include"bits/stdc++.h"
using namespace std;
int Main();
int t=Main();
int main(){};
int Main()
{
    long long n,m,a,b;
    cin>>n>>m>>a>>b;
    n%=m;
    cout<<min(n*b,(m-n)*a)<<endl;
    return 0;
}