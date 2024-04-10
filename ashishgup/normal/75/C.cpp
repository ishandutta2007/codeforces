#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b;
vector<int> v;

int32_t main()
{
    IOS;
    cin>>a>>b;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            if(b%i==0)
                v.push_back(i);
            if(b%(a/i)==0)
                v.push_back(a/i);
        }
    }
    sort(v.begin(), v.end());
    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        auto it=upper_bound(v.begin(), v.end(), r);
        it--;
        if(*it<l)
            cout<<"-1"<<endl;
        else
            cout<<*it<<endl;
    }
    return 0;
}