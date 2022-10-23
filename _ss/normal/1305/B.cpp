#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    vector<int> ans1,ans2;
    int l=0,r=(int)s.length()-1;
    while (l<r)
    {
        while (l<(int)s.length() && s[l]!='(') l++;
        while (r>=0 && s[r]!=')') r--;
        if (l>r) break;
        ans1.pb(l+1);
        ans2.pb(r+1);
        l++;
        r--;
    }
    if (ans1.size()==0)
    {
        cout<<0;
        return 0;
    }
    cout<<1<<"\n";
    cout<<ans1.size()*2<<"\n";
    for (int x : ans1) cout<<x<<" ";
    for (int i=ans2.size()-1;i>=0;i--) cout<<ans2[i]<<" ";
    return 0;
}