#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 998244353;

string a, l, r;

vector<int> z_function (string s) 
{
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) 
    {
        if (i <= r)
        z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
        ++z[i];
        if (i+z[i]-1 > r)
        {l = i, r = i+z[i]-1;}
    }
    return z;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>a>>l>>r;
    vector<int> a1 = z_function(l+'#'+a);
    vector<int> a2 = z_function(r+'#'+a);
    //for (int i = 0; i<a1.size(); i++) cout<<a1[i]<<endl;
    int L = l.length();
    int R = r.length();
    int A = a.length();
    vector<int> low(A, 0);
    for (int i = 0; i<A; i++) low[i] = a1[L+1+i];
    vector<int> up(A, 0);
    for (int i = 0; i<A; i++) up[i] = a2[R+1+i];
    
    vector<ll> result(2000002, 0);
    vector<pair<int, int>> ans(A);
    for (int i = 0; i<A; i++)
    {
        ans[i].first = 0;
        ans[i].second = 0;
        if (low[i]==L) ans[i].first = i+L;
        else if (i+low[i]>=A) ans[i].first = A+1;
        else
        {
            if (a[i+low[i]]>l[low[i]]) ans[i].first = i+L;
            else ans[i].first = i+L+1;
        }
        
        if (up[i]==R) ans[i].second = i+R;
        else if (i+up[i]>=A) ans[i].second = A;
        else
        {
            if (a[i+up[i]]>r[up[i]]) ans[i].second = i+R-1;
            else ans[i].second = i+R;
        }
    }
    
    

    
    result[A] = 1;
    for (int j = ans[A-1].first; j<=ans[A-1].second; j++) {result[A-1]+=result[j]; result[A-1]%=N;}
    
    ll cur, curl, curr;
    cur = A-1;
    curl = ans[A-1].first;
    curr = ans[A-1].second;
    
    
    for (int i = A-2; i>=0; i--)
    {
        if (ans[i].first>ans[i].second) continue;
        /*if (ans[i+1].first>ans[i+1].second)
        {*/
            if (a[i]=='0') {if (l=="0") result[i] = result[i+1];}
            else if (a[i]!='0'&&ans[cur].first<=ans[cur].second)
            {
                result[i] = result[cur];
                for (int j = ans[cur].first-1; j>=ans[i].first; j--) {result[i]+=result[j]; result[i]%=N;}
                for (int j = ans[cur].second; j>ans[i].second; j--) {result[i]-=result[j]; result[i]%=N;}  
                cur = i;
                curl = ans[i].first;
                curr = ans[i].second;
            }
            else 
            {
                for (int j = ans[i].first; j<=ans[i].second; j++) {result[i]+=result[j]; result[i]%=N;}
                cur = i;
                curl = ans[i].first;
                curr = ans[i].second;
            }
        /*}
        else
        {
            result[i] = result[i+1];
            for (int j = ans[i+1].first-1; j>=ans[i].first; j--) {result[i]+=result[j]; result[i]%=N;}
            for (int j = ans[i+1].second; j>ans[i].second; j--) {result[i]-=result[j]; result[i]%=N;}
        }*/
        if (result[i]<0) result[i]+=N;
    }
//    for (int i = 0; i<A; i++) cout<<result[i]<<endl;
    
    result[0]%=N;
    if (result[0]<0) result[0]+=N;
    cout<<result[0];
}