#include <bits/stdc++.h>
#define ll long long

using namespace std;
string s1;
ll t,x,s,mj,j,n,i,k;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    //s++;
    x=s;
    t=s;
    j=1;
    while(x>0)
    {
        j*=10;
        x/=10;

    }
    j/=10;
    s=(s/j+1)*j;
    cout << s-t << endl;
    return 0;
}