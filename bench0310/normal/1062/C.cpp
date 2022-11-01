#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    int n,q;
    cin >> n >> q;
    vector<ll> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
    string s;
    cin >> s;
    s="$"+s;
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]-'0');
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        ll a=sum[r]-sum[l-1];
        ll b=r-l+1-a;
        cout << (p[a]-1+(p[a]-1)*(p[b]-1))%mod << "\n";
    }
    return 0;
}