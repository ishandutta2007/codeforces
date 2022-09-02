#include<bits/stdc++.h>
using namespace std;

long long f(long long n, long long x, bool chet)
{
    if (chet) return x+1;
    else 
    {
        if (n%2==0) return f(n, n/2+x/2, (n%2+x%2)%2);
        else return f(n, n/2 + (x+1)/2, (n%2+x%2)%2);
    }
}

int main()
{
long long n, q;
cin>>n>>q;
long long x;
for (int i = 0; i<q; i++)
{
    cin>>x; cout<<f(n, x/2, x%2)<<endl;
}

}