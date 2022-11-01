#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int n;
    cin >> n;
    vector<int> v[N+1];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        while(a>1)
        {
            int p=sieve[a];
            int c=0;
            while(sieve[a]==p)
            {
                c++;
                a/=p;
            }
            v[p].push_back(c);
        }
    }
    ll res=1;
    for(int i=2;i<=N;i++)
    {
        if((int)v[i].size()==n-1) v[i].push_back(0);
        if((int)v[i].size()<n) continue;
        sort(v[i].begin(),v[i].end());
        for(int j=1;j<=v[i][1];j++) res*=i;
    }
    cout << res << "\n";
    return 0;
}