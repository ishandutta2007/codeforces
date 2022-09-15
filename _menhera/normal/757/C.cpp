#include<cstdio>
#include<set>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;
int N, M;
set<int> calc[2010101];
int tp = 1;
int inset[1010101];
const int MOD = 1e9+7;
int fact[1010101];
int pow(int a, int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    long long ans = pow(a,b/2);
    ans *= ans;
    ans %= MOD;
    if(b%2==1) ans *=a;
    ans %= MOD;
    return ans;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1; i<=M; i++) calc[0].insert(i);
    fact[0]=1;
    for(int i=1; i<=M; i++) fact[i]=(1LL*i*fact[i-1])%MOD;
    for(int i=0; i<N; i++)
    {
        int Q;
        scanf("%d",&Q);
        unordered_map<int, int> cntM;
        map< pair<int, int>,vector<int> > MM;
        for(int j=0; j<Q; j++)
        {
            int t;
            scanf("%d",&t);
            cntM[t] = cntM[t]+1;
        }
        for(auto it = cntM.begin(); it!=cntM.end(); it++)
        {
            auto k = make_pair(it->second,inset[it->first]);
            if(MM.find(k)==MM.end())
            {
                vector<int> nv;
                MM[k] = nv;
            }
            MM[k].push_back(it->first);
        }
        for(auto it =MM.begin(); it!=MM.end(); it++)
        {
            int ind = it->first.second;
            vector<int> topush = it->second;
            for(int x:topush)
            {
                calc[ind].erase(x);
                calc[tp].insert(x);
                inset[x]=tp;
            }
            ++tp;
        }
    }
    int ans = 1;
    for(int i=0;i<2001010;i++)
        if(calc[i].size())
        {
            int v = fact[calc[i].size()];
            ans = (1LL*ans*v)%MOD;
        }
    printf("%d\n",ans);
    return 0;
}