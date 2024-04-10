#include <bits/stdc++.h>

using namespace std;

int n, ki, t[2][101], a;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) {
        t[0][i]=t[1][i]=min(t[0][i-1],t[1][i-1])+1;
        cin >> a;
        if(a%2 && t[1][i-1]<t[0][i]) t[0][i]=t[1][i-1];
        if(a/2 && t[0][i-1]<t[1][i]) t[1][i]=t[0][i-1];
    }
    cout << min(t[0][n],t[1][n]) <<endl;
    return 0;
}