#include <iostream>
#include <string>

using namespace std;

long n,k;
string s;

void two(void){
    long a=0,b=0;
    for (long i=0; i<n; ++i)
    if ((s[i]=='A')^(i%2==0))
    b++;
    else
    ++a;

    if (a<b){
        cout<<a<<"\n";
        for (long i=0; i<n; ++i)
        (i%2) ? cout<<"A":cout<<"B";
    }
    else{
        cout<<b<<"\n";
        for (long i=0; i<n; ++i)
        !(i%2) ? cout<<"A":cout<<"B";
    }

}

char third(char a, char b){
    if (a!='A' && b!='A')
    return 'A';
    if (a!='B' && b!='B')
    return 'B';
    if (a!='C' && b!='C')
    return 'C';
}

void big(void){
    long t=0;
    for (long i=1; i<n; ++i)
    if (s[i-1]==s[i]){
        t++;
        if (i+1<n)
        s[i]=third(s[i-1],s[i+1]);
        else
        s[i]=third(s[i-1],s[i-1]);
    }
    cout<<t<<"\n";
    cout<<s;
}

int main()
{
    cin>>n>>k>>s;
    if (k==2)
    two();
    else
    big();
    return 0;
}