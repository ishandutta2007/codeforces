#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<bool> now(k,0);
    now[0]=1;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin >> a >> b;
        vector<bool> nxt(k,0);
        for(int j=0;j<k;j++)
        {
            nxt[j]=now[(j-(a%k)+k)%k];
            for(int l=0;l<=min(k-1,a);l++) if(((a-l)%k)+b>=k) nxt[j]=(nxt[j]|now[(j-l+k)%k]);
        }
        sum+=(a+b);
        now=nxt;
    }
    ll res=0;
    for(int i=0;i<k;i++) if(now[i]==1) res=max(res,(sum-i)/k);
    cout << res << "\n";
    return 0;
}