#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1;

int main()
{
    int n;
    cin>>n;
    if (n==1) cout<<n; else cout<<(n)*(n-1)*2+1;
    return 0;
}