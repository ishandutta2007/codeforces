#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(vector<int> v)
{
    int x=-1;
    int res=0;
    for(int a:v)
    {
        if(a==0) res++;
        else if(x==-1||((res+1)&1)==x)
        {
            res++;
            x=(res&1);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> b=a;
    sort(b.begin(),b.end());
    int l=-1,r=n-1;
    while(l<r-1)
    {
        int m=(l+r)/2;
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=(a[i]>b[m]);
        if(solve(v)>=k) r=m;
        else l=m;
    }
    cout << b[r] << "\n";
    return 0;
}