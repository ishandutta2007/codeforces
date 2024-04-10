#include <iostream>
#include <string>
#include <algorithm>

#define M 5000
#define f first
#define s second

using namespace std;

long n,a[M],t[M],po=0;
pair<long, string> m[M];

bool add(long pos,long num){
    if (pos>po)
    return 0;
    po++;
    for (long i=po; i>pos; --i)
    t[i]=t[i-1];
    t[pos]=num;
    return 1;
}

int main()
{
    cin>>n;
    for (long i=0; i<n; ++i)
    cin>>m[i].s>>m[i].f;
    sort(m,m+n);

    for (long i=0; i<n; ++i)
    if (!add(m[i].f,i)){
        cout<<-1;
        return 0;
    }

    for (long i=0; i<n; ++i)
    a[t[i]]=33100-i;

    for (long i=0; i<n; ++i)
    cout<<m[i].s<<" "<<a[i]<<"\n";

    return 0;
}