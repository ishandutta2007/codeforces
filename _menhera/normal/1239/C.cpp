#include<bits/stdc++.h>
using namespace std;
int N; long long p;
const int MAXN = 131072;

int idx[2*MAXN];
int getv(int a, int b)
{
    int ans = 0;
    a += MAXN; b += MAXN;
    while(a <= b)
    {
        if(a%2==1) ans += idx[a++];
        if(b%2==0) ans += idx[b--];
        a/=2; b/=2;
    }
    return ans;
}
void setv(int a, int v)
{
    idx[a+=MAXN] = v;
    while((a=a/2))
        idx[a] = idx[2*a] + idx[2*a+1];
}
int main()
{
    using pli = pair<long long, int>;
    queue<int> realQ;
    priority_queue<int, vector<int>,greater<int>> fakeQ;
    scanf("%d%lld", &N, &p);
    vector<long long> ans(N);
    vector<pair<long long, int> > V;
    for(int i=0; i<N; ++i)
    {
        long long x; scanf("%lld", &x);
        V.emplace_back(x, i);
        setv(i, 0);
    }
    sort(V.begin(), V.end());
    int idx = 0;
    long long T = 0;
    while(true)
    {
        if(!realQ.empty())
        {
            int x = realQ.front(); realQ.pop();
            T += p;
            ans[x] = T;
            while(idx < N && V[idx].first < T)
            {
                if(getv(0, V[idx].second) == 0)
                {
                    //printf("R %d\n", V[idx].second);
                    realQ.push(V[idx].second);
                    setv(V[idx].second, 1);
                }
                else
                {
                    //printf("F %d\n", V[idx].second);
                    fakeQ.push(V[idx].second);
                }
                ++idx;
            }
            setv(x, 0);
            while(idx < N && V[idx].first == T)
            {
                //printf("!F %d\n", V[idx].second);
                fakeQ.push(V[idx].second);
                ++idx;
            }
            if(!fakeQ.empty())
            {
                int x = fakeQ.top();
                if(getv(0, x) == 0)
                {
                    fakeQ.pop();
                    //printf("F->Q %d\n", x);
                    realQ.push(x);
                    setv(x, 1);
                }
            }
        }
        else // all empty
        {
            //printf("!R %d\n", V[idx].second);
            if(idx == N) break;
            realQ.push(V[idx].second);
            setv(V[idx].second, 1);
            T = V[idx].first;
            ++idx;
        }
    }
    for(int i=0; i<N; ++i) printf("%lld ", ans[i]);
    puts("");
    return 0;
}