#include <bits/stdc++.h>

using namespace std;

#define TASK "test"

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    string ok1="^>v<";
    string ok2=">v<^";
    string t="";
    t+=a[n-1];
    t+=b[0];
    t+=a[0];
    t+=b[m-1];
    if(t==ok2)
    {
        cout<<"YES";
        return 0;
    }
    t="";
    t+=b[0];
    t+=a[0];
    t+=b[m-1];
    t+=a[n-1];
    if(t==ok1)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}