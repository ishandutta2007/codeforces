#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;
map<int,int> mp;

signed main()
{
    int n,k;
    cin>>n>>k;
    int now=0;
    int sum=0;
    multiset<int> setik;

    while (n!=0)
    {
        sum+=n%2;

        mp[now]+=n%2;
        if (n%2)
            setik.insert(now);
        n/=2;
        now++;

    }

    if (sum>k)
    {
        cout<<"No";
        return(0);
    }

    while (setik.size()!=k)
    {
        int last=*setik.rbegin();

        if (mp[last]<=k-int(setik.size()))
        {
            mp[last]=0;
            while (*setik.rbegin()==last)
            {
                setik.erase(setik.find(last));
                setik.insert(last-1);
                setik.insert(last-1);
                mp[last-1]+=2;
            }
        } else
        {
            while (setik.size()!=k)
            {
                last=*setik.begin();
                setik.erase(setik.find(last));
                setik.insert(last-1);
                setik.insert(last-1);
            }
        }
    }
    cout<<"Yes"<<'\n';
    vector<int> vec;
    for (auto i:setik)
        vec.pb(i);
    reverse(vec.begin(),vec.end());
    for (auto i:vec)
        cout<<i<<' ';

}

/*
1
10
1 2 3 4 5 6 7 8 9 10
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/