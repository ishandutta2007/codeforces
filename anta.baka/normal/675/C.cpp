#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans=0;
    cin>>n;
    long long s=0;
    map<long long, int> cnt;
    for(int i=0, num; i<n; i++)
    {
        cin>>num;
        s+=num;
        cnt[s]++;
        ans=max(ans,cnt[s]);
    }
    cout<<n-ans;
    return 0;
}