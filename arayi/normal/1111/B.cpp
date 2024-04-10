#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;

long long a[N];

int main()
{
    long long n, k, m, i, sum=0, tp;
    long double mx;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    // Sorting the array
    sort(a+1, a+n+1);
    // Checking for the case where none of the avengers is removed
    mx = (long double)(sum+min(m, n*k))/(long double)(n);
 
    for(int i=1;i<=min(n-1, m);i++)
    {
        sum -= a[i];
        tp = sum + min(m-i, (n-i)*k);
        mx = max(mx, (long double)(tp)/(long double)(n-i));
    }
    cout<<fixed<<setprecision(20)<<mx<<endl;
    return 0;
}