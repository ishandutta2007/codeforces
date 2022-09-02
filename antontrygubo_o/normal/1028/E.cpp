#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    ll maxx = -1;
    ll minn = 1000000000;
    int zeros = 0;
    for (int i = 0; i<n; i++)
    {
        if (a[i]!=0) minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
        if (a[i]==0) zeros++;
    }
    
    if (zeros==n)
    {
        cout<<"YES"<<endl;
        for (int i = 0; i<n; i++) cout<<1<<' ';
        return 0;
    }
    
    if (zeros==n-1)
    {
        cout<<"YES"<<endl;
        int idx = -1;
        for (int i = 0; i<n; i++) if (a[i]==maxx) idx = i;
        for (int j = 0; j<idx; j++) cout<<2*maxx<<' ';
        cout<<maxx<<' ';
        for (int j = idx+1; j<n; j++) cout<<2*maxx<<' ';
        return 0;
    }
    
    if (minn==maxx&&zeros==0)
    {
        cout<<"NO"; return 0;
    }
        
    if (minn==maxx)
    {
        cout<<"YES"<<endl;
        vector<ll> answer(n, 0);
        for (int i = 0; i<n; i++) if (a[i]==0) answer[(i+1)%n] = maxx;
        for (int i = 0; i<2*n; i++) if (a[i%n]!=0&&answer[i%n]==maxx) 
        {
            answer[(i+1)%n] = 1000000000*maxx; 
            while (a[(i+1)%n]!=0) 
            {
                i++;
                answer[(i+1)%n] = answer[i%n]-maxx;
            }
        }
        for (int i = 0; i<n; i++) cout<<answer[i]<<' ';
        return 0;
    }
    
    
    
    
    cout<<"YES"<<endl;
    int idx = -1;
    int prev = 1000000000;
    for (int i = 0; i<2*n; i++) 
    {
        
        if (a[i%n]==maxx&&prev<maxx) idx = i%n;
        if (a[i%n]!=0) prev = a[i%n];
        
    }
    
    vector<ll> answer(n);
    answer[idx] = maxx;
    for (int i = 0; i<n-1; i++) answer[(idx+n-1-i)%n] = answer[(idx+n-i)%n] + a[(idx+n-i-1)%n];
    for (int i = 0; i<n; i++) cout<<answer[i]<<' ';
    cout<<endl;
    

    
    
}