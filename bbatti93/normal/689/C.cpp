#include <bits/stdc++.h>

using namespace std;

long long m,a,b;
bool jo;

int main()
{
    cin >> m;
    a=1;
    b=8*m;
    while(a<=b) {
        long long c=(a+b)/2;
        long long k=0;
        for(long long i=2;i*i*i<=c;i++) k+=c/i/i/i;
        if(k==m) jo=true;
        if(k<m) a=c+1;
        else b=c-1;
    }
    if(jo) cout << a << endl;
    else cout << -1 <<endl;
    return 0;
}