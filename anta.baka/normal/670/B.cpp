#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    long long sum=0;
    int pos=0;
    for(; pos<n && sum<k; pos++) sum+=pos+1;
    sum-=pos-1;
    for(pos=0; sum<k; pos++, sum++) {}
    cout<<a[pos];
    return 0;
}