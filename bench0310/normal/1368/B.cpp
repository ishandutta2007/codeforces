#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin >> k;
    auto p=[](ll b)->ll
    {
        ll res=1;
        for(int i=1;i<=10;i++) res*=b;
        return res;
    };
    ll a=1;
    while(p(a)<k) a++;
    ll x=p(a);
    int c=0;
    while((x/a)*(a-1)>=k)
    {
        x=(x/a)*(a-1);
        c++;
    }
    string s="codeforces";
    for(int i=0;i<10-c;i++) for(int j=0;j<a;j++) cout << s[i];
    for(int i=10-c;i<10;i++) for(int j=0;j<a-1;j++) cout << s[i];
    cout << "\n";
    return 0;
}