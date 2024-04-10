#include <iostream>
#include <string>

#define M 100100

using namespace std;

char c[M];
long n,m=0,k=0,f[M];
string s;
bool u[M];

bool open(char ch){
    return ch=='[' || ch=='(';
}

bool good(char x, char y){
    if (y==']')
    return x=='[';
    return x=='(' && y==')';
}

void doit(void){
    long d=0,l,r;

    for (long r=0; r<n; r++)
    if (open(s[r])){
        c[m]=s[r];
        f[m++]=r;
    }
    else
    if (m>0 && good(c[m-1],s[r])){
        m--;
        u[f[m]]=1;
        u[r]=1;
    }
    else
    m=0;

    for (long i=0,j=0;i<n; i=j){
        while (j<n && u[j]){
            if (s[j]=='[')
            ++d;
            ++j;
        }
        if (k<d){
            k=d;
            l=i;
            r=j;
        }
        d=0;
        j++;
    }

    cout<<k<<"\n";
    if (k>0)
    cout<<s.substr(l,(r-l));
}

int main()
{
    cin>>s;
    n=s.length();
    doit();
    return 0;
}