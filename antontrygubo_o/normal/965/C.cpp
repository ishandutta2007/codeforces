#include<bits/stdc++.h>
using namespace std;


int main()
{

long long n, k, M, D;
cin>>n>>k>>M>>D;
long long maxx = 0;
for (int i = 1; i<=min(D, (n-1)/(k)+1); i++)
{
    long long r = n/((i-1)*k+1);
    long long l = (n/(i*k+1))+1;
    if (l<=M) 
    {
        long long x = min(r, M);
        maxx = max(maxx, x*i);
        //cout<<i<<' '<<x<<endl;
    }
    
}
cout<<maxx;
}