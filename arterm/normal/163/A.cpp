#include <iostream>
#include <string>

#define p 1000000007
#define M 5055
#define long long long

using namespace std;

long ls,lt,d[M][M];
string s,t;

void read(void){
    cin>>s>>t;
    ls=s.length();
    lt=t.length();
}

void din(void){
    for (long i=0; i<ls; ++i)
    for (long j=0; j<lt; ++j){
        if (j>0)
        d[i][j]+=d[i][j-1];
        if (s[i]==t[j])
        d[i][j]+=1;
        if (i>0 && j>0 && s[i]==t[j])
        d[i][j]+=d[i-1][j-1];
        d[i][j]%=p;
    }
}



int main()
{
    read();
    din();
    long s=0;
    for (long i=0; i<ls; ++i)
    s+=d[i][lt-1];
    s%=p;
    cout<<s;
    return 0;
}