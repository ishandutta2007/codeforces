#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

int p = 10007;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int M = 22;
    int N = 1<<M;
    int n;
    cin>>n;
    vector<int> a(n);
    get(a);
    vector<int> cnt(N);
    vector<int> present(N, -1);
    for (int i = 0; i<n; i++) cnt[a[i]]++;
    
    
    for (int mask = 0; mask<N; mask++)
    {
        if(cnt[mask]!=0) present[mask] = mask;
        for (int i = 0; i<M; i++)
        {
            if (mask&(1<<i)) 
            {
                if (present[mask^(1<<i)]!=-1) present[mask] = present[mask^(1<<i)];
            }
        }
    }
    
    for (int i = 0; i<n; i++) cout<<present[N-1-a[i]]<<' ';
    

}