#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
    sort(v.begin(),v.end());
    long long s=0;
    for(int i=0;i<n/2;i++) s+=(v[i]+v[n-i-1])*(v[i]+v[n-i-1]);
    printf("%I64d\n",s);
    return 0;
}