#include <bits/stdc++.h>

using namespace std;

int solve(string s)
{
    int n=s.size();
    vector<int> d1(n,0);
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int k=(i > r)?1:min(d1[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]) k++;
        d1[i]=k--;
        if(i+k>r)
        {
            l=i-k;
            r=i+k;
        }
    }
    vector<int> d2(n,0);
    for (int i=0,l=0,r=-1;i<n;i++) {
        int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
        while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k]) k++;
        d2[i]=k--;
        if(i+k>r)
        {
            l=i-k-1;
            r=i+k;
        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(d1[i]==i+1) res=max(res,2*i+1);
        if(d2[i]==i) res=max(res,2*i);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n=s.size();
        int cnt=0;
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r]) break;
            l++;
            r--;
            cnt+=2;
        }
        if(l==r||cnt==n)
        {
            cout << s << "\n";
            continue;
        }
        string x=s.substr(cnt/2,n-cnt);
        int one=solve(x);
        reverse(x.begin(),x.end());
        int two=solve(x);
        if(one>=two)
        {
            reverse(x.begin(),x.end());
            cout << s.substr(0,cnt/2);
            cout << x.substr(0,one);
            cout << s.substr(n-cnt/2,cnt/2);
            cout << "\n";
        }
        else
        {
            cout << s.substr(0,cnt/2);
            string y=x.substr(0,two);
            reverse(y.begin(),y.end());
            cout << y;
            cout << s.substr(n-cnt/2,cnt/2);
            cout << "\n";
        }
    }
    return 0;
}