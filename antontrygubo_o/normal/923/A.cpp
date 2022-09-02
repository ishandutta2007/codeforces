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

int INF = 1000001;

vector<int> min_prime(INF);

vector<int> max_prime(INF);

void init()
{
    for (int i = 2; i<=INF; i++)
    {
        if (min_prime[i]==0)
        {
            min_prime[i] = i;
            for (int j = i; j<=INF; j+=i) if (min_prime[j]==0) min_prime[j] = i;
        }
    }
    
    for (int i = 2; i<=INF; i++)
    {
        if (min_prime[i]==i) max_prime[i] = i;
        else max_prime[i] = max_prime[i/min_prime[i]];
    }
    
}

void solve (int n)
{
    int p = max_prime[n];
    int res = n;
    for (int i = n; i>n-p; i--) if (max_prime[i]!=i) res = min(res, i-max_prime[i]+1);
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int n;
    cin>>n;
    solve(n);

}