#include<bits/stdc++.h>
using namespace std;

long long pow2[10101];
char s[101010];
int countx[101010];
int N;
map<pair<int, bool>, vector<int> > M;
const int MOD = 1e9+7;
vector<int> solve(int x, bool free)
{
    if(M.find(make_pair(x, free)) != M.end())
        return M[make_pair(x, free)];
    vector<int> res(1010);
    if(s[x] == 0)
    {
        res[0] = 1;
        return M[make_pair(x, free)] = res;
    }
    if(free)
    {
        vector<int> res2 = solve(x+1, true);
        res[0] = res2[0];
        for(int i=1; i<1010; ++i)
            res[i] = (res2[i] + res2[i-1])%MOD;;
        return M[make_pair(x, free)] = res;
    }
    if(s[x] == '0')
        return M[make_pair(x, free)] = solve(x+1, false);
    vector<int> res2 = solve(x+1, false);
    res = solve(x+1, true);
    for(int i=1; i<1010; ++i)
        res[i] = (res[i]+res2[i-1])%MOD;
    
    return res;
}
int main()
{
    int k;
    scanf("%s%d", s, &k);
    if(k==0)
    {
        puts("1");
        return 0;
    }
    for(int i=1; i<=1000; ++i)
    {
        int cnt = 0, j = i;
        while(j!=1)
        {
            j = __builtin_popcount(j);
            ++cnt;
        }
        countx[i] = cnt;
    }
    vector<int> ans = solve(0,false);
    long long r = 0;
    for(int i=1; i<1010; ++i)
    {
        //if(i<4) printf("%d: %d\n", ans[i]);
        if(countx[i] == k-1) 
            r += ans[i];
        r %= MOD;
    }
    if(k==1)
    {
        r += MOD-1; r %= MOD;
    }
    printf("%lld\n", r);
    return 0;
}