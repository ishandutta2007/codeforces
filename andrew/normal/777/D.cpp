#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s[1000000];
ll i,n,j,nn;
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(i=1;i<=n;i++)cin >> s[i];
    for(i=n-1;i>0;i--)
    {
        s1='#';
        nn=s[i].size();
        for(j=1;j<nn;j++)
            {
                s1+=s[i][j];
                if(s1>s[i+1])
                {
                    s[i]=s1.substr(0,j);
                    break;
                }
            }
    }
    for(i=1;i<=n;i++)cout << s[i] << "\n";
    return 0;
}