#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    else return gcd(b,a%b);
}

int main()
{
    int n,m;
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    string t[m];
    for(int i=0;i<m;i++) cin >> t[i];
    int q;
    cin >> q;
    int l=n*m/gcd(n,m);
    while(q--)
    {
        int y;
        cin >> y;
        y--;
        y%=l;
        int one=y%n,two=y%m;
        cout << s[one]+t[two] << endl;
    }
    return 0;
}