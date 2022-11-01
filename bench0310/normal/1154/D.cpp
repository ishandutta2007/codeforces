#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,b,m;
    cin >> n >> b >> m;
    int a=m;
    bool v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            if(a==m) a--;
            else if(b>0) b--,a++;
            else if(a>0) a--;
            else break;
        }
        if(v[i]==0)
        {
            if(a>0) a--;
            else if(b>0) b--;
            else break;
        }
        res=i+1;
    }
    cout << res << endl;
    return 0;
}