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
typedef long double ld;
const int arr=3e5;

int get(int u)
{
    vector<int> vec;
    for (int i=1;i<=u;i++)
        vec.pb(i);

    int res=0;
    do
    {
        bool ch=1;
        for (int i=0;i<vec.size();i++)
            if (vec[i]==i+1)
            ch=0;
        res+=ch;
    }
        while (next_permutation(vec.begin(),vec.end()));


    return(res);
}

int get(int n, int k)
{
    if (k==2)
    {
        return(n*(n-1)/2*get(k));
    } else
    if (k==3)
    {
        return(n*(n-1)*(n-2)/6*get(k));
    } else
    {
        return(n*(n-1)*(n-2)*(n-3)/6/4*get(k));
    }
}

int solve(int u, int cnt)
{
    vector<int> vec;
    for (int i=1;i<=u;i++)
        vec.pb(i);

    int res=0;
    do
    {
        int c=0;
        for (int i=0;i<vec.size();i++)
            if (vec[i]!=i+1)
            c++;
        if (c==cnt)
            res++;
    }
        while (next_permutation(vec.begin(),vec.end()));
    return(res);
}

signed main()
{
    int n,k;
    cin>>n>>k;
    int ans=1;

    for (int i=2;i<=k;i++)
    {
        ans+=get(n,i);
    }



    cout<<ans;
}