#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n, m;
    cin>>n>>m;
    bool k = true;
    while (k)
    {
        if (n==0||m==0) k = false;
        else
        {
            if (n>=2*m) n = n%(2*m);
            else if (m>=2*n) m = m%(2*n);
            else k = false;
        }
    }
    cout<<n<<' '<<m;
    
}