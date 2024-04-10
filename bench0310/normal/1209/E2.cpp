#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto mx=[](int &a,int b){a=max(a,b);};
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(m,vector<int>(n,0));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[j][i];
        vector<array<int,2>> z(m);
        for(int i=0;i<m;i++)
        {
            int x=0;
            for(int j=0;j<n;j++) x=max(x,a[i][j]);
            z[i]={x,i};
        }
        sort(z.begin(),z.end(),greater<array<int,2>>());
        vector<vector<int>> b(min(m,n));
        for(int i=0;i<min(n,m);i++) b[i]=a[z[i][1]];
        vector<int> now((1<<n),0);
        for(vector<int> &v:b)
        {
            vector<int> best((1<<n),0);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<(1<<n);j++)
                {
                    int s=0;
                    for(int k=0;k<n;k++) if(j&(1<<k)) s+=v[k];
                    mx(best[j],s);
                }
                int x=v.back();
                v.pop_back();
                v.insert(v.begin(),x);
            }
            vector<int> nxt=now;
            for(int i=0;i<(1<<n);i++)
            {
                for(int j=i;j>0;j=(j-1)&i) mx(nxt[i],now[i^j]+best[j]);
            }
            now=nxt;
        }
        cout << now[(1<<n)-1] << "\n";
    }
    return 0;
}