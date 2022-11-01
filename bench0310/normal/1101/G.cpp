#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]^=a[i-1];
    }
    if(a[n]!=0)
    {
        const int d=30;
        vector<int> basis(d,0);
        int sz=0;
        for(int i=n;i>=1;i--)
        {
            int m=a[i];
            for(int j=0;j<d;j++)
            {
                if((m&(1<<j))==0) continue;
                if(basis[j]!=0) m^=basis[j];
                else
                {
                    basis[j]=m;
                    sz++;
                    break;
                }
            }
        }
        cout << sz << "\n";
    }
    else cout << "-1\n";
    return 0;
}