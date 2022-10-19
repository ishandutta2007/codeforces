#include <bits/stdc++.h>
using namespace std;
long long m,n,a,b,t,t1,t2;
int main()
{
    cin >> m >> n >> a >>b;
    t= m / n;
    t1=(m-(n*t))*b;
    t2=(n-(m-(n*t)))*a;
    if (t1<t2) t2=t1;
    cout << t2;
}