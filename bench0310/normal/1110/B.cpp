#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k;
    cin >> n >> m >> k;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<long long> len;
    for(int i=1;i<n;i++)
    {
        len.push_back(a[i]-a[i-1]-1);
    }
    sort(len.begin(),len.end());
    long long sum=n;
    for(int i=0;i<n-k;i++) sum+=len[i];
    cout << sum << endl;
    return 0;
}