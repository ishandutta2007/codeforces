#include <iostream>
#include <vector>
#include <algorithm>

#define M 1001000
#define long long long

using namespace std;

long n,m,d[M],s=0;

void read(void){
    cin>>n>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        d[a]++;
        d[b]++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    read();
    for (long i=1; i<=n; ++i)
    s=s+d[i]*(n-1-d[i]);
    s/=2;
    cout<<n*(n-1)*(n-2)/6-s;

    return 0;
}