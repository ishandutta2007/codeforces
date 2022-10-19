#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,k,t;
    long long x1,x2,y1,y2;
    cin >> n >> m >> k;
    long long tich=2*m*n;
    long long tich2=tich/k;
    long long tichdu=tich%k;
    if (tichdu==0)
    {
        cout << "YES" << endl;
        y2=m;
        x1=tich2/y2+1;
        x2=1;y1=y2-tich2%y2;
        if (k==2)
        {
            y2=m;x1=n;x2=0;y1=1;
        }
        cout << 0 << " " << 0 << endl;
        cout << x1 << " " << y1 << endl;
        cout << x2 << " " << y2 ;
    }
    else cout << "NO" ;
}