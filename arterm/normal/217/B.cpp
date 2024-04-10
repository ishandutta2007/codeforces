#include <iostream>
#include <string>

#define M 1010101

using namespace std;

string ans,s;
long bet=1<<25;

void tr(long a, long b, long t){
    long u=0,m=0;
    while (a!=1 || b!=1){
        if (a>b){
            s[u++]='T';
            a-=b;
        }
        if (a<b){
            s[u++]='B';
            b-=a;
        }
        if (a==b && a>1){
            m=1<<20;
            break;
        }
    }
    s[t]='T';
    if (u==t)
    for (long i=0; i<t; ++i)
    if (s[i]==s[i+1])
    m++;
    if (u==t && m<bet){
        bet=m;
        ans=s;
    }

}

int main()
{
    long n,r;
    ans.resize(M);
    s.resize(M);
    cin>>n>>r;
    n--;
    for (long i=1; i<=r; ++i)
    tr(r,i,n);
    for (long i=1; i<=r; ++i)
    tr(i,r,n);
    if (bet<M){
        cout<<bet<<endl;
        for (long i=n; i>=0; --i)
        cout<<ans[i];
    }
    else
    cout<<"IMPOSSIBLE";
    return 0;
}