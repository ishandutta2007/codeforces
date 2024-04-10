#include <iostream>
#include <string>

#define M 121

using namespace std;

long rev(long x){
    long a=0;
    for (long i=0; i<8; ++i){
        a<<=1;
        a+=(x&1);
        x>>=1;
    }
    return a;
}

int main()
{
    long n,t[M];
    string s;
    getline(cin,s);
    n=s.length();

    t[0]=0;
    for (long i=0; i<n; ++i)
    t[i+1]=rev(s[i]);

    for (long i=0; i<n; ++i)
    cout<<(t[i]-t[i+1]+256)%256<<"\n";

    return 0;
}