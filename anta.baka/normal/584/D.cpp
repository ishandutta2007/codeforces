#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int n;
    cin>>n;
    if(is_prime(n)) { cout<<"1\n"<<n; return 0; }
    if(is_prime(n-2)) { cout<<"2\n2 "<<n-2; return 0; }
    for(int i=n-4;; i-=2)
        if(is_prime(i))
            for(int j=2; ; j++)
                if(is_prime(j) && is_prime(n-i-j))
                {
                    cout<<"3\n"<<i<<' '<<j<<' '<<n-i-j;
                    return 0;
                }
}