#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long long h;
    cin >> n >> h;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int l=1,r=n+1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        vector<int> v;
        for(int i=0;i<m;i++) v.push_back(a[i]);
        sort(v.begin(),v.end());
        long long cnt=0;
        for(int i=m-1;i>=0;i-=2) cnt+=(long long)v[i];
        if(cnt<=h) l=m;
        else r=m;
    }
    cout << l << endl;
    return 0;
}