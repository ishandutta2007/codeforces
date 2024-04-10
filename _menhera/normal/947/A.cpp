#include<bits/stdc++.h>
using namespace std;
vector<int> factorize(int N)
{
    vector<int> ans;    
    for(int i=2; i*i<=N; ++i)
    {
        while(N%i==0)
        {
            ans.push_back(i);
            N /= i;
        }
    }
    if(N!=1) ans.push_back(N);
    return ans;
}
vector<int> top(int N)
{
    vector<int> f = factorize(N);
    vector<int> ans;
    for(int i=N-f[f.size()-1]+1; i<=N; ++i)
        ans.push_back(i);
    return ans;
}
int main()
{
    int N; scanf("%d", &N);
    vector<int> possible = top(N);
    int ans = N;
    for(auto x: possible)
    {
        vector<int> a = factorize(x);
        if(a.size() == 1) continue;
        ans = min(ans, x-a[a.size()-1]+1);
    }
    printf("%d\n", ans);
    return 0;
}