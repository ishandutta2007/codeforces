#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

string s;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int l=0,r=s.length()-1,check=1;
    while (l<=r)
    {
        if (s[l]!=s[r]) check=0;
        int d=2;
        while (l<s.length() && s[l]==s[l+1]) l++,d++;
        while (r>=0 && s[r]==s[r-1]) r--,d++;
        l++;
        r--;
        if (d<3) check=0;
    }
    if (l-r-1>=2 && check) cout<<l-r;
    else cout<<0;
    return 0;
}