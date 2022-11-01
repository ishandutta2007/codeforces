#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        s="$"+s;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]-'0');
        int res=n;
        auto zero=[&](int l,int r)->int{if(l>r) return 0; else return (r-l+1-(sum[r]-sum[l-1]));};
        auto one=[&](int l,int r)->int{if(l>r) return 0; else return (sum[r]-sum[l-1]);};
        for(int i=0;i<=n;i++)
        {
            res=min(res,zero(1,i)+one(i+1,n));
            res=min(res,one(1,i)+zero(i+1,n));
        }
        cout << res << "\n";
    }
    return 0;
}