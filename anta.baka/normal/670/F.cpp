#include <bits/stdc++.h>
using namespace std;

inline int f(int n) {
    int res=0;
    while(n) { res++; n/=10; }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string s, sb;
    cin>>s>>sb;
    if(s=="01"||s=="10") { cout<<0; return 0; }
    int n=s.length(), len;
    for(len=1; len<n && len+f(len)!=n; len++) {}
    string ans;
    for(int i=0; i<len; i++)
        ans+='9';
    vector<int> cnt(10,0);
    while(len) { cnt[len%10]++; len/=10; }
    for(int i=0; i<sb.length(); i++) cnt[sb[i]-'0']++;
    vector<char> ns;
    for(int i=0; i<n; i++)
        if(cnt[s[i]-'0'])
            cnt[s[i]-'0']--;
        else
            ns.push_back(s[i]);
    sort(ns.begin(),ns.end());
    if(sb[0]!='0')
    {
        string temp;
        temp=sb;
        for(int i=0; i<ns.size(); i++)
            temp+=ns[i];
        ans=min(ans,temp);
    }
    if(ns.size()&&ns.back()!='0')
    {
        string temp;
        int p;
        for(int i=0; i<ns.size(); i++)
            if(ns[i]!='0')
            {
                temp+=ns[i];
                p=i;
                break;
            }
        int i;
        for(i=0; i<ns.size() && ns[i]<sb[0]; i++)
            if(i!=p)
                temp+=ns[i];
        temp+=sb;
        for(; i<ns.size(); i++)
            if(i!=p)
                temp+=ns[i];
        ans=min(ans,temp);
    }
    if(ns.size()&&ns.back()!='0')
    {
        string temp;
        int p;
        for(int i=0; i<ns.size(); i++)
            if(ns[i]!='0')
            {
                temp+=ns[i];
                p=i;
                break;
            }
        int i;
        for(i=0; i<ns.size() && ns[i]<=sb[0]; i++)
            if(i!=p)
                temp+=ns[i];
        temp+=sb;
        for(; i<ns.size(); i++)
            if(i!=p)
                temp+=ns[i];
        ans=min(ans,temp);
    }
    cout<<ans;
    return 0;
}