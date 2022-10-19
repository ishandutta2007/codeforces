#include <iostream>
#include <vector>

#define N 1000100

using namespace std;

const long C=1<<22;

vector<long> a(C,0),d(C,0),t(N);

int main()
{
    long n;
    cin>>n;
    for (long i=1; i<=n; ++i){
        cin>>t[i];
        a[t[i]]=i;
    }


    for (long i=1; i<C; ++i)
    if (a[i]>0)
    d[i]=a[i];
    else
    for (long j=1; j<C; j<<=1)
    if ((j&i) && d[i-j]>0){
        d[i]=d[i-j];
        break;
    }


    for (long i=1; i<=n; ++i)
    d[C-1-t[i]]>0 ? cout<<t[d[C-1-t[i]]]<<" " : cout<<-1<<" ";

    return 0;
}