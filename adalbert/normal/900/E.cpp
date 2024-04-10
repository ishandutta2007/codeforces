#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
#define int ll
typedef long long ll;
typedef double ld;
const int arr=5e5;

int md=1e9+7;

int pred[arr],good[arr],last0[arr],last1[arr],start[arr],cost[arr],res[arr],mx[arr];

signed main()
{
    int n;
    cin>>n;
    string st;
    cin>>st;
    int m;
    cin>>m;

    for (int i=1;i<=st.size();i++)
        pred[i]=pred[i-1]+(st[i-1]=='?');

    for (int i=1;i<=st.size();i++)
        cost[i]=pred[i+m-1]-pred[i-1];

    for (int i=1;i<=st.size();i++)
        if (st[i-1]=='a' && i%2)
        start[i]=1; else
        if (st[i-1]=='a' && i%2==0)
        start[i]=-1; else
        if (st[i-1]=='b' && i%2==0)
        start[i]=1; else
        if (st[i-1]=='b' && i%2)
        start[i]=-1;

    last1[st.size()+1]=st.size()+1;
    last0[st.size()+1]=st.size()+1;

    for (int i=st.size();i>=1;i--)
    {
        if (start[i]==1)
            last1[i]=i; else
            last1[i]=last1[i+1];
        if (start[i]==-1)
            last0[i]=i; else
            last0[i]=last0[i+1];
    }

    for (int i=1;i<=st.size();i++)
    {
        if (i%2)
        {
            if (last0[i]-i>=m)
                good[i]=1;
        } else
        {
            if (last1[i]-i>=m)
                good[i]=1;
        }
    }


    for (int i=st.size();i>=1;i--)
    {
        mx[i]=mx[i+1];
        if (good[i])
        {
            mx[i]=max(mx[i],1+mx[i+m]);
        }
    }

    for (int i=st.size();i>=1;i--)
    {
        res[i]=1e18;
        if (mx[i]==mx[i+1])
            res[i]=min(res[i],res[i+1]);
        if (good[i])
            res[i]=min(res[i],res[i+m]+cost[i]);
    }

    cout<<res[1];
}