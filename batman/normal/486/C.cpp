#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (501)

ll n,p,sum;
string s;
vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>s;
    p--;
    p=min(p,(ll)s.size()-p-1);
    for(int i=0;i<(ll)s.size()/2;i++)
        v.push_back(min(abs((s[i]-'a')-(s[(ll)s.size()-i-1]-'a')),26-abs((s[i]-'a')-(s[(ll)s.size()-i-1]-'a')))),sum+=v[i];
    if(!v.size())return cout<<0,0;  
    ll l=0,r=v.size()-1; 
    while(l!=p && v[l]==0)l++;
    while(r!=p && v[r]==0)r--;
    cout<<sum+min((p-l)*2+(r-p),(r-p)*2+(p-l)); 
    return 0;
}