#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

int main()
{
    long long n, k;
    cin>>n>>k;
    if (k==0) {cout<<0<<' '<<0; return 0;}
    if (k==n) {cout<<0<<' '<<0; return 0;}
    cout<<1<<' '<<min(n-k, 2*k);
}