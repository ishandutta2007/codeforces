#include <iostream>

using namespace std;

long long ab(long long x)
{
    if(x<0) return -x;
    else return x;
}

int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0;i<n;i++) cin >> arr[i];
    long long m=1000000000;
    for(long long x=1;x<=n;x++)
    {
        long long res=0;
        for(long long i=1;i<=n;i++) res+=arr[i-1]*2*(ab(x-i)+i+x-2);
        m=min(m,res);
    }
    cout << m << endl;
    return 0;
}