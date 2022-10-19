#include <iostream>
#include <string>

#define M 1001001

using namespace std;

long n,p[M],d[M];
string s;

void pref(void){
    n=s.length();
    for (long i=1; i<n; ++i){
        p[i]=p[i-1];
        while (s[p[i]]!=s[i] && p[i]>0)
        p[i]=p[p[i]-1];
        if (s[p[i]]==s[i])
        ++p[i];
        d[p[i]]++;
    }
}

void doit(void){
    long h=p[n-1];
    if (d[h]==1 && h>0)
    h=p[h-1];
    if (h==0)
    cout<<"Just a legend";
    else
    cout<<s.substr(0,h);
}

int main()
{
    cin>>s;
    pref();
    doit();
    return 0;
}