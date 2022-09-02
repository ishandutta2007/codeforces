#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    
    const int N = 15000000;
    vector<int> lp(N+1);
    vector<int> pr;
    for (int i=2; i<=N; ++i) 
    {
        if (lp[i] == 0) 
        {
            lp[i] = i;
            pr.push_back (i);
        }
       for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    int gcd = a[0];
    for (int i = 1; i<n; i++) gcd = __gcd(gcd, a[i]);
    for (int i = 0; i<n; i++) a[i]/=gcd;
    
    bool check = false;
    for (int i = 0; i<n; i++) if (a[i]!=1) check = true;
    if (!check) {cout<<-1; return 0;}
    
    vector<int> lol(N+1, 0);
    for (int i = 0; i<n; i++)
    {
        while (a[i]!=1)
        {
            int temp = lp[a[i]];
            lol[temp]++;
            while (a[i]%temp==0) a[i]/=temp;
        }
    }
    int maxx = 0;
    for (int i = 0; i<pr.size(); i++) maxx = max(maxx, lol[pr[i]]);
    cout<<n-maxx;
}