#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;

int main()
{
    //freopen("ss.inp","r",stdin);
    int n;
    cin>>n;
    vector<pii> odd,even;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if ((i+j)&1) odd.eb(i,j);
            else even.eb(i,j);
    for (int i=1;i<=n*n;i++)
    {
        int x;
        cin>>x;
        if (x==1)
        {
            if (!even.empty())
            {
                pii p=even.back();
                even.pop_back();
                cout<<"2 "<<p.fi<<" "<<p.se<<endl;
            }
            else
            {
                pii p=odd.back();
                odd.pop_back();
                cout<<"3 "<<p.fi<<" "<<p.se<<endl;
            }
        }
        else
        {
            if (!odd.empty())
            {
                pii p=odd.back();
                odd.pop_back();
                cout<<"1 "<<p.fi<<" "<<p.se<<endl;
            }
            else
            {
                pii p=even.back();
                even.pop_back();
                if (x==2) cout<<"3 ";
                else cout<<"2 ";
                cout<<p.fi<<" "<<p.se<<endl;
            }
        }
    }
    return 0;
}