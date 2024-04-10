#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    //freopen("ss.inp","r",stdin);
    //freopen("ss.out","w",stdout);
    int n;
    cin>>n;
    int t=1;
    while (t<=n) t<<=1;
    if (n&1) cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        vector<int> ans;
        int tmp=t-1,k=n;
        while (k>0)
        {
            for (int i=k;i>=(k^tmp);i--) ans.pb(i^tmp);
            k^=tmp;
            k--;
            while ((tmp^k)>k) tmp>>=1;
        }
        for (int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    }
    cout<<endl;
    if (n==t/2 || n<6) cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        if (n==6) cout<<"3 6 2 5 1 4";
        else
        {
            cout<<"7 3 2 5 1 4 6 ";
            if (n>7)
            {
                if (n&1) for (int i=8;i<=n;i++) cout<<(i^1)<<" ";
                else
                {
                    for (int i=8;i<=n-3;i++) cout<<(i^1)<<" ";
                    cout<<n-1<<" "<<n<<" "<<n-2;
                }
            }
        }
    }
    return 0;
}