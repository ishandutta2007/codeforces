#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll N, M;

const ll p = 1000000007;

vector<ll> a;

vector<ll> difs;

vector<ll> hhash;

vector<ll> backhash;

set<ll> ans;

vector<ll> degs;

void check (int start, int end)
{
    ll sum1 = hhash[end];
    if (start>0) sum1 = (sum1+p-hhash[start-1])%p;
    ll sum2 = backhash[start];
    if (end<2*N-1) sum2 = (sum2+p-backhash[end+1])%p;
    if ((sum1*degs[2*N-1-end]-sum2*degs[start])%p==0) 
    {
        ans.insert((a[start%N]+a[(end+1)%N])%M);    
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    a.resize(N);
    hhash.resize(2*N);
    backhash.resize(2*N);
    degs.resize(2*N);
    degs[0] = 1;
    for (int i = 1; i<2*N; i++) degs[i] = degs[i-1]*(M+1)%p;
    for (int i = 0; i<N; i++) cin>>a[i];
    
    for (int i = 0; i<2*N; i++) difs.push_back((a[(i+1)%N]+M-a[i%N])%M);
    
    
    hhash[0] = difs[0];
    ll current = M+1;
    for (int i = 1; i<2*N; i++) {hhash[i] = (hhash[i-1]+current*difs[i])%p; current = (current*(M+1))%p;}
    backhash[2*N-1] = difs[2*N-1];
    current = M+1;
    for (int i = 2*N-2; i>=0; i--) {backhash[i] = (backhash[i+1]+current*difs[i])%p; current = (current*(M+1))%p;}
    
    /*for (int i = 0; i<2*N; i++) cout<<difs[i]<<' ';
    cout<<endl;*/
    
    for (int i = 0; i<N; i++) check(i, i+N-1);
    for (int i = 0; i<N; i++) check(i, i+N-2);
    
    
    cout<<ans.size()<<endl;
    for (auto it = ans.begin(); it!=ans.end(); it++) cout<<*it<<' ';
}