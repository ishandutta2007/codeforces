#include <bits/stdc++.h>

using namespace std;

const long long M=1000000007;
int n, k;
long long ki,a, b;
bool t[10];
long long fact[200001], factinv[200001];

long long modinv(long long a, long long m) {
    long long b=m-2;
    long long ki=1;
    while(b>0) {
        if(b&1)ki=(ki*a)%m;
        a=(a*a)%m;
        b=b>>1;
    }
    return ki;
}
bool has(const pair<int,int>& a, const pair<int,int>&b) {
    return a.first<b.first;
}

long long alatt(long long a, long long b) {
    return ((fact[a]*factinv[b])%M*factinv[a-b])%M;
}

vector<pair<int,int> > v;

int main()
{
    cin >> n >> k;
    fact[0]=factinv[0]=1;
    for(int i=1;i<=n;i++) {
        fact[i]=(fact[i-1]*i)%M;
        factinv[i]=modinv(fact[i],M);
    }
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        v.push_back(make_pair(a,1));
        v.push_back(make_pair(b+1,-1));
    }
    sort(v.begin(),v.end(), has);
    int most=v[0].second;
    for(int i=1;i<v.size();i++) {
        if(most>=k) {
            ki=(ki+alatt(most,k)*(v[i].first-v[i-1].first))%M;
        }
        most+=v[i].second;
    }
    cout << ki;
    return 0;
}