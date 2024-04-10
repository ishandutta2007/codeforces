#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e15)
#define N (2002)

ll k,a,b,v,i;

int main()
{
    cin>>k>>a>>b>>v;
    for(i=0;a>0;i++)
    {
        ll section=min(k,b+1);
        b-=section-1;
        a-=section*v;
    }
    cout<<i;
    return 0;
}