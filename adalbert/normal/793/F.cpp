#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int k=300;
const int arr=1e5+100;
vector<int> vec[arr];
vector<pair<int,int> > steck[arr/k+10];
int too[arr][arr/k+10],from[arr];
int get_ans(int l, int r, int x)
{
    //cout<<l<<' '<<r<<' '<<x<<"##########"<<'\n';
    for (int i=max(r/k*k,x)+1;i<=r;i++)
    {
        if (from[i]>=l && from[i]<=x)
            x=i;
    }
    return(x);
}
signed main()
{
    fast;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i=1;i<=n;i++)
        from[i]=i;
    while (m--)
    {
        int l,r;
        cin>>l>>r;
        vec[l].pb (r);
        from[r]=l;
    }
    for (int i=1;i<=n;i++)
    {
        vec[i].pb(i);
        vec[i].pb(1e9);
        sort(vec[i].begin(),vec[i].end());
        int last=0;
        for (int j=1;j*k<=n;j++)
        {
            while (vec[i][last]<=j*k) last++;
            if (last==0) continue;
            too[i][j]=vec[i][last-1];
        }
    }
    for (int i=n;i>=0;i--)
        for (int j=1;j*k<=n;j++)
        if (i<=k*j)
            too[i][j]=max(too[i][j],i);
    for (int j=1;j*k<=n;j++)
        steck[j].pb({n+1,0});
    for (int i=n;i>=1;i--)
        for (int j=1;j*k<=n;j++)
        {
            while (too[i][j]>=steck[j][steck[j].size()-1].fir)
            {
                too[i][j]=max(too[i][j],steck[j][steck[j].size()-1].sec);
                steck[j].pop_back();
            }
            steck[j].pb({i,too[i][j]});
        }
    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;

        cout<<get_ans(l,r,max(l,too[l][r/k]))<<'\n';
    }
}
/*
10
10
3 7
1 4
1 6
5 5
1 1
3 9
7 8
1 2
3 3
7 10
1
1 7
*/