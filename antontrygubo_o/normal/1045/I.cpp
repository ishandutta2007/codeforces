#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll degs[26];
vector<ll> nums;

ll counter(ll x)
{
    auto s = lower_bound(nums.begin(), nums.end(), x);
    auto r = upper_bound(nums.begin(), nums.end(), x);
    return int (r-s);
}

int main(){
    ios_base::sync_with_stdio(false);
    degs[0] = 1;
    for (int i = 1; i<26; i++) degs[i] = 2*degs[i-1];
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        string s;
        cin>>s;
        ll a[26] = {};
        for (int j = 0; j<s.length(); j++)
        {a[int(s[j]-'a')]++; a[int(s[j]-'a')]%=2;}
        ll k = 0;
        for (int j = 0; j<26; j++) k+=a[j]*degs[j];
        nums.push_back(k);
    }
    sort(nums.begin(), nums.end());
    
    ll answer = 0;
    
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<26; j++)
        {
            answer+=counter(nums[i]^degs[j]);
        }
        answer+=counter(nums[i]);
        answer--;
    }
    answer/=2;
    cout<<answer;
    /*cout<<endl;    
    for (int i = 0; i<n; i++) cout<<nums[i]<<' ';*/
    
}