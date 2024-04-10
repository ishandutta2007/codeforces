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
int a[N];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,u,v;
        cin>>n>>u>>v;
        set<int> st;
        for (int i=1,x;i<=n;i++) cin>>x,st.insert(x),a[i]=x;
        int check=1;
        for (int i=1;i<n;i++)
            if (abs(a[i]-a[i+1])>1) check=0;
        if (check)
        {
            if (st.size()==1) cout<<v+min(u,v)<<"\n";
            else cout<<min(u,v)<<"\n";
        }
        else cout<<"0\n";
    }
    return 0;
}