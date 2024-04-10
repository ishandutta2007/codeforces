#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll c=0,a,b,sc=0;
    cin >> a >> b;
    while(1)
    {
        c++;
        if(sc==0)
        {
            if(a<c){cout << "Vladik" << endl; return 0;}
            a-=c;
        }else
        {

            if(b<c){cout << "Valera" << endl; return 0;}
           b-=c;

        }
        sc=1-sc;
    }
    return 0;
}