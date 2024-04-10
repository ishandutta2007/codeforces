#include <iostream>
#include <algorithm>

#define long long long
#define INF 1000000000000LL
#define M 100100

using namespace std;

long n,a[M],x,t=0,m;
bool flag=0;

void read(void){
    cin>>n>>x;
    x--;
    m=INF;
    for (long i=0; i<n; ++i){
        cin>>a[i];
        m=min(m,a[i]);
    }
}

void kill(void){
    long y=0,i=x;
    for (; a[i]!=0; i=(i+n-1)%n)
    a[i]--,y++;
    for (long j=0; j<n; ++j,cout<<" ")
    if (j==i)
    cout<<y;
    else
    cout<<a[j];
}

void clever(void){
    long i=x,y=0;
    for (; a[i]!=m; i=(n+i-1)%n)
    a[i]--,y++;
    for (long j=0; j<n; ++j,cout<<" ")
    if (j==i)
    cout<<n*m+y;
    else
    cout<<a[j]-m;


}


int main()
{
    read();
    if (m==0)
    kill();
    else
    clever();

    return 0;
}