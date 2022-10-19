#include <iostream>
#include <vector>
#include <string>

#define M 200100

using namespace std;

string s,t;
long n,m,l[M],r[M];
bool fl=1;
vector<long> v[500];

bool bin(long x, long y, char ch){
    if (v[ch].empty())
    return 0;
    long l=0,r=v[ch].size()-1,m;
    while (l<r){
        m=(l+r)/2;
        if (v[ch][m]+1>=x)
        r=m;
        else
        l=m+1;
    }
    return v[ch][l]+1>=x && v[ch][l]-1<=y;
}

void greed(void){
    long u=0;
    char ch;

    cin>>s>>t;
    n=s.length();
    m=t.length();

    l[0]=0;
    r[n]=0;


    for (long i=0; i<m; ++i)
    v[t[i]].push_back(i);

    for (long i=0; i<n;++i){
        if (u<m && s[i]==t[u])
        u++;
        l[i]=u-1;
    }

    if (u<m)
    fl=0;

    u=m-1;
    for (long i=n-1; i>=0;--i){
        if (u>=0 && s[i]==t[u])
        u--;
        r[i]=u+1;
    }

    if (u>=0)
    fl=0;

    if (l[0]==-1)
    fl=0;
    if (r[n-1]==m)
    fl=0;

    for (long i=1; i+1<n; ++i)
    fl&=bin(r[i+1],l[i-1],s[i]);

    if (fl)
    cout<<"Yes";
    else
    cout<<"No";



}

int main()
{
    greed();
    return 0;
}