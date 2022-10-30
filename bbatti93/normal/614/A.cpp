#include <bits/stdc++.h>

using namespace std;
long long l,r,k,lk,ki=0;
int main()
{
    cin >> l >> r >> k;
    if(l==1) {cout << 1 << " ";ki++;}
    for(long long kk=1;kk<=r/k;kk*=k) {
        if(l<=kk*k) {cout << kk*k << " ";ki++;}
    }
    if(!ki) cout << -1;
    cout << endl;
    return 0;
}