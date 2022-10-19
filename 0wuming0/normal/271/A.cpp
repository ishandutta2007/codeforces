#include"bits/stdc++.h"
using namespace std;
bool solve(int n)
{
    int a=n%10;
    n/=10;
    int b=n%10;
    n/=10;
    int c=n%10,d=n/10;
    if(a==b||a==c||a==d||b==c||b==d||c==d)return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;n++;
    while(solve(n))n++;
    cout<<n<<endl;
    return 0;
}