#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k,m;
    cin >> n >> k >> m;
    long long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    long long sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    double res=(sum+min(m,n*k))/(double)n;
    for(long long i=0;i<min(n-1,m);i++)
    {
        sum-=a[i];
        res=max(res,(sum+min(m-i-1,(n-i-1)*k))/(double)(n-i-1));
    }
    cout << fixed << setprecision(12) << res << endl;
    return 0;
}