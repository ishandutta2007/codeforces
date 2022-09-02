#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<ll> t(n);
    for (int i = 0; i<n; i++) cin>>t[i];
    //print(t);
    vector<ll> ans(n+1);
    ans[0] = 0;
    for (int i = 1; i<=n; i++)
    {
        ans[i] = ans[i-1] + 20;
        int k = upper_bound(t.begin(), t.end(), t[i-1]-90) - t.begin();
        //cout<<i<<' '<<k<<' ';
        ans[i] = min(ans[i], ans[k] + 50);
        k = upper_bound(t.begin(), t.end(), t[i-1]-1440) - t.begin();
        ans[i] = min(ans[i], ans[k] + 120);
        //cout<<k<<' '<<ans[i]<<endl;
    }
    //print(ans);
    for (int i = 1; i<=n; i++) cout<<ans[i]-ans[i-1]<<endl;

}