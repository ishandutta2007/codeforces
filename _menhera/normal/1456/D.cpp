#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5000;

vector<pair<long long, long long> > Range[MAXN+1]; // Time ti, clone @xi, my range?
bool D[MAXN+1][MAXN+1]; // Time ti, I am @xi, clone @xj possible? (i < j)
int N;
long long t[MAXN+1], x[MAXN+1];


vector<pair<long long, long long> > normalize(vector<pair<long long, long long> > V)
{
    if(V.size() == 0) return V;
    sort(V.begin(), V.end());
    pair<long long, long long> x = V[0];
    vector<pair<long long, long long> > U;
    for(int i=1; i<(int)V.size(); ++i)
    {
        if(x.second >= V[i].first)
            x.second = max(x.second, V[i].second);
        else
        {
            U.push_back(x);
            x = V[i];
        }
    }
    U.push_back(x);
    return U;
}

// Distance between range and index
long long getD(pair<long long, long long> a, long long b)
{
    if(a.first <= b && b <= a.second) return 0;
    return min(abs(a.first-b), abs(a.second-b));
}

// Distance between Range[i] and x[k]
long long getS(int i, int k)
{
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    auto it = lower_bound(Range[i].begin(), Range[i].end(), make_pair(x[k], INF));
    auto it2 = it == Range[i].begin() ? it : prev(it);
    long long dis = INF;
    if(it != Range[i].end()) dis = min(dis, getD(*it, x[k]));
    if(it2 != Range[i].end()) dis = min(dis, getD(*it2, x[k]));
    return dis;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) scanf("%lld%lld", t+i, x+i);
    Range[0].emplace_back(0, 0);
    for(int i=1; i<=N; ++i) if(x[i] == 0) D[0][i] = true;
    for(int i=0; i<N; ++i)
    {
        // [s, e] => xk => xi+1 possible then Di+1, k
        for(int k=i+2; k<=N; ++k)
            if(getS(i, k)+abs(x[k]-x[i+1]) <= t[i+1]-t[i])
                D[i+1][k] = true;

        // i finished => i+1 clone
        long long dis = getS(i, i+1);
        long long rem = t[i+1]-t[i] - dis;
        if(rem >= 0) Range[i+1].emplace_back(x[i+1]-rem,x[i+1]+rem);

        // D i,k -> D i+1, k
        for(int k=i+2; k<=N; ++k)
            if(D[i][k] && abs(x[i+1]-x[i]) <= t[i+1]-t[i])
                D[i+1][k] = true;

        // D i, i+1 -> pass i+1
        if(D[i][i+1])
            Range[i+1].emplace_back(x[i]-(t[i+1]-t[i]), x[i]+(t[i+1]-t[i]));

        Range[i+1] = normalize(Range[i+1]);
        /*
        printf("About %d Time: %lld, Position: %lld\n",i+1, t[i+1], x[i+1]);
        printf("Time ti, clone @xi, my range: ");
        for(auto [s, e]: Range[i+1]) printf("[%lld, %lld]; ", s, e);
        puts("");
        printf("Time ti, @xi, clone @xj possible?\n");
        for(int k=i+2; k<=N; ++k) printf("%d: %s\n", k, D[i+1][k]?"YES":"NO");
        puts("\n");
        */

    }
    if(Range[N].size()) puts("YES");
    else puts("NO");
}