#include<bits/stdc++.h>
using namespace std;

vector<long long> factor(long long tg)
{
    vector<long long> factors;
    for(long long i=2; i*i<=tg; i++)
        if(tg%i==0)
        {
            factors.push_back(i);
            while(tg%i == 0) tg /= i;
        }
    if(tg!=1) factors.push_back(tg);
    return factors;
}

int N; long long K;
long long A[1010101], E[1010101];
long long DP[12][2048];
int main()
{
    scanf("%d%lld", &N, &K);
    for(int i=0; i<N; ++i) scanf("%lld", A+i);
    for(int i=0; i<N; ++i) scanf("%lld", E+i);
    long long g = A[0]; for(int i=1; i<N; ++i) g = gcd(A[i], g);
    if(g==1){ puts("0"); return 0;}

    vector<long long> factors = factor(g);
    map<long long, vector<long long> > M;
    for(int i=0; i<N; ++i)
    {
        long long tostore=1, na = A[i];
        for(auto v: factors)
        {
            while(na%v == 0)
            {
                tostore *= v;
                na /= v;
            }
        }
        M[tostore].push_back(E[i]);
    }

    memset(DP, 0x3f, sizeof DP); DP[0][0] = 0;
    for(auto& [a, v]: M)
    {
        sort(v.begin(), v.end());
        if(v.size() > factors.size()) v.resize(factors.size());
        long long qf[11];

        for(int i=0; i<(int)factors.size(); ++i)
        {
            long long na = a;
            qf[i] = 1;
            while(na%factors[i] == 0)
                na /= factors[i], qf[i] *= factors[i];
        }
        long long val[2048];
        for(int i=0; i<(1<<factors.size()); ++i)
        {
            val[i] = 1;
            for(int j=0; j<(int)factors.size(); ++j)
                if(i&(1<<j))
                    val[i] *= qf[j];
        }
        for(auto vv: v)
        {
            bool chan = false;
            for(int i=(int)factors.size()-1; i>=0; --i)
                for(int j=0; j<(1<<factors.size()); ++j)
                {
                    long long mv = DP[i+1][j];
                    for(int k=0; k=(k-j)&j; )
                        if(val[k] <= K)
                            mv = min(mv, DP[i][j-k]+vv);
                    if(mv != DP[i+1][j]) chan = true;
                    DP[i+1][j] = mv;
                }
            if(!chan) break;
        }
    }
    long long ans = (long long)1e15;
    for(int i=1; i<=(int)factors.size(); ++i)
        if(DP[i][(1<<(int)factors.size())-1] < (long long)1e12)
            ans = min(ans, i*DP[i][(1<<(int)factors.size())-1]);
    if(ans >= (long long)1e15) ans = -1;
    printf("%lld\n", ans);
}