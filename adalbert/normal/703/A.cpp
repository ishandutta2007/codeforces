#include <bits/stdc++.h>
using namespace std;
long long n,a,b,k1,k2;
string st;
long long month[13]={29, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
double sqr(double u)
{
    return(u*u);
}
string string_int (long long u)
{
    string str;
    while (u!=0)
    {
        str+=u%10+48;
        u/=10;
    }
    reverse(str.begin(),str.end());
    return(str);
}
long long nsk (long long i, long long j)
{
    while (i!=0 && j!=0)
        if (i>j) i%=j; else j%=i;
    return(i+j);
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if (a>b) k1++; else
            if (b>a) k2++;
    }
    if (k1>k2) cout<<"Mishka"; else
        if (k2>k1) cout<<"Chris"; else cout<<"Friendship is magic!^^";
}