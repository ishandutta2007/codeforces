#include <bits/stdc++.h>

using namespace std;

#define TASK "test"
#define int long long

const int maxn=1e5+1;
const int INF=2e9;

const int POW=1<<18;
const int POW2=1<<19;

struct segment_tree
{
    int sum[POW2],num[POW2];

    void add(int x,int t)
    {
        int pl=t*x;
        x+=POW;
        do sum[x]+=pl,num[x]+=t;while(x>>=1);
    }

    int get_sum(int c,int cn,int n)
    {
        //cout<<num[c<<1]<<endl;
        if(cn==n) return 0;
        //cout<<num[c]<<endl;
        //cout<<n<<' '<<cn<<' '<<c-POW<<endl;
        if((c<<1)>POW2) return (c-POW)*(n-cn);
        if(cn+num[c<<1]>n) return get_sum(c<<1,cn,n);
        else return sum[c<<1]+get_sum((c<<1)+1,cn+num[c<<1],n);
    }

    int get_sum(int n)
    {
        if(n<=0) return 0;
        return get_sum(1,0,n);
    }
} me;

 main()
 {
    #ifndef ONLINE_JUDGE
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<pair<int,int>> cand; //  ,  
    vector<multiset<int>> vote(maxn);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a) me.add(b,1);
        vote[a].insert(b);
    }
    for(int i=1;i<maxn;i++) cand.insert({vote[i].size(),i});
    int ans=INF;
    int CONST_SUM=0;
    int cur=vote[0].size();
    for(int i=n;i>=max(1ll,(int)vote[0].size());i--) //       
    {
        for(auto it=cand.lower_bound({i,0});it!=cand.end();)
            {
                cur++;
                CONST_SUM+=*vote[it->second].begin();
                me.add(*vote[it->second].begin(),-1);
                vote[it->second].erase(vote[it->second].begin());
                cand.insert({it->first-1,it->second});
                cand.erase(it++);
            }
        ans=min(ans,CONST_SUM+me.get_sum(i-cur));
        //cout<<i<<' '<<CONST_SUM<<' '<<ans<<' '<<i-cur<<endl;
        //cout<<i<<' '<<cur<<' '<<ans<<' '<<CONST_SUM<<endl;
    }
    cout<<ans<<endl;
 }