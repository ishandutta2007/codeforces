#include <iostream>

#define M 200200

using namespace std;

long s[M],n=0;

bool pr(char ch){
    if (ch=='a' ||
        ch=='e' ||
        ch=='o' ||
        ch=='u' ||
        ch=='i')
    return 1;
    return 0;
}

void read(void){
    char ch;
    s[0]=0;
    while (cin>>ch){
        if (ch=='!')
        break;
        ++n;
        if ('A'<=ch && ch<='Z')
        ch-=('A'-'a');
        if (pr(ch))
        s[n]=s[n-1]-1;
        else
        s[n]=s[n-1]+2;
    }
}

bool check(long d){
    long l=0;
    long m=s[0];
    while (l+d<=n){
        if (m<=s[l+d])
        return 1;
        m=min(m,s[++l]);
    }
    return 0;
}

long bin(void){
    long l=0, r=n,m;
    while (l<r){
        m=(l+r+2)/2;
        if (check(m))
        l=m;
        else
        r=m-1;
    }
    return l;
}


int main()
{
    long b,c=0;
    read();
    b=bin();
    for (long i=b; i<=n ;++i)
    if (s[i]>=s[i-b])
    ++c;
    if (b>0)
    cout<<b<<" "<<c;
    else
    cout<<"No solution";
    return 0;
}