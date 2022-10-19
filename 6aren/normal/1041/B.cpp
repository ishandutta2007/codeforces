#include <bits/stdc++.h>
using namespace std;
long long m,n,p,q;
long long ucln(long long a,long long b)
{
    //cout << a << " " << b << endl;
    if (a==0) return b;
    if (b==0) return a;
    if (a > b) return ucln(a%b,b);
    else return ucln(a,b%a);
}
int main()
{
    cin >> m >> n >> p >> q;
    long long t=ucln(p,q);
    //cout << t << endl;
    p=p/t;q=q/t;
    //cout << p << " " << q << endl;
    cout << min(m/p,n/q);
}