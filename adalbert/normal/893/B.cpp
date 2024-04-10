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

typedef long long ll;
typedef double ld;
const int arr=6e5;


bool check(int u)
{
    vector<int> vec;
    while (u!=0)
    {
        vec.pb(u%2);
        u/=2;
    }

    if (vec.size()%2==0)
        return(0);


    reverse(vec.begin(),vec.end());

    int k=vec.size()/2+1;

    for (int i=0;i<k;i++)
        if (vec[i]==0)
        return(0);
    for (int i=k;i<vec.size();i++)
        if (vec[i]==1)
        return(0);


    return(1);
}

signed main()
{
    int ans=1;

    int n;
    cin>>n;


    for (int i=1;i<=n;i++)
        if (n%i==0)
        if (check(i))
        ans=i;

    cout<<ans;
}
/*

*/