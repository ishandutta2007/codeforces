#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;
string s;
int presum[maxn];
int main()
{
    cin>>s;
    presum[0]=(s[0]=='Q');
    for (int i=1;i<s.length();i++) presum[i]=presum[i-1]+(s[i]=='Q');
    ll ans=0;
    for (int i=1;i<s.length();i++)
        if (s[i]=='A') ans+=presum[i]*(presum[s.length()-1]-presum[i]);
    cout<<ans;
    return 0;
}