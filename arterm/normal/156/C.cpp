#include <iostream>
#include <string>

#define long long long
#define p 1000000007
#define L 111
#define S 3000


using namespace std;

long d[L][S];

void pre(void){
    for (long i=0; i<S; ++i)
    d[1][i]=0;
    for (long i=0; i<26; ++i)
    d[1][i]=1;
    for (long l=2; l<101; ++l)
    for (long s=0; s<S; ++s){
        d[l][s]=0;
        for (long j=0; j<26 && s-j>=0; ++j)
        d[l][s]=(d[l-1][s-j]+d[l][s])%p;
    }
}

long sum(string s){
    long n=s.length(), ans=0;
    for (long i=0; i<n; ++i)
    ans+=(s[i]-'a');
    return ans;
}

int main()
{
    long t;
    string s;
    cin>>t;
    pre();
    for (long i=0; i<t; ++i){
        cin>>s;
        cout<<(d[s.length()][sum(s)]+p-1)%p<<"\n";
    }
    return 0;
}