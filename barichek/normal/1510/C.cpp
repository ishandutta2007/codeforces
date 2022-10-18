//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1e5+10, inf = 1000111222;

vector<int> reb[max_n];
vector<int> reb2[max_n];
bool used[max_n];
bool marked_up[max_n];
int predok[max_n];
pii ans[max_n];
int sz_ans;

int dp[max_n][2];
int go[max_n][2];
bool cur_in_dfs1[max_n];

set<int> reb_set[max_n];
set<pii> marked_cur;

void mark_cur(int u,int v)
{
    marked_cur.insert(mp(u,v));
    marked_cur.insert(mp(v,u));
}

void dfs1(int now,int pred=-1)
{
    cur_in_dfs1[now]=1;
//    cout<<"dfs1 :: "<<now<<"\n";
    predok[now]=pred;
    used[now]=1;
    for (auto wh:reb[now]){
        if (!used[wh]){
            dfs1(wh,now);
        }
        else if (cur_in_dfs1[wh] && wh!=pred){
            int cur=now;
            while (cur!=wh){
                marked_up[cur]=1;
                cur=predok[cur];
            }
        }
        else if (wh!=pred){
            int cur=wh;
            while (cur!=now){
                marked_up[cur]=1;
                cur=predok[cur];
            }
        }
    }
    cur_in_dfs1[now]=0;
}

void do_if_update(int& a,int b,int& c,int d)
{
    if (a>b){
        a=b;
        c=d;
    }
}

void dfs2(int now,bool is_root)
{
//    cout<<"dfs2 :: "<<now<<"\n";
    for (auto wh:reb[now]){
        dfs2(wh,false);
    }

    /// calc dp[now][0]
    if (!is_root) {
        int sum=0;
        for (auto wh:reb[now]){
            sum+=dp[wh][1]+1;
        }
        dp[now][0]=sum-len(reb[now])/2;

        go[now][0]=inf;
    }
    else{
        // if no noncolored
        int sum=0;
        for (auto wh:reb[now]){
            sum+=dp[wh][1]+1;
        }
        dp[now][0]=sum-len(reb[now])/2;
        go[now][0]=inf;

        // if now<->wh noncolored
        for (auto wh:reb[now]){
            sum-=dp[wh][1]+1;

            do_if_update(dp[now][0], sum-(len(reb[now])-1)/2 + dp[wh][0],       go[now][0], wh);

            sum+=dp[wh][1]+1;
        }
    }

    /// calc dp[now][1]
    if (!is_root) {
        // if no noncolored
        int sum=0;
        for (auto wh:reb[now]){
            sum+=dp[wh][1]+1;
        }
        dp[now][1]=sum-len(reb[now])/2-(len(reb[now])%2==1);
        go[now][1]=inf;


        // if now<->wh noncolored
        for (auto wh:reb[now]){
            sum-=dp[wh][1]+1;

            do_if_update(dp[now][1], sum-(len(reb[now])-1)/2-((len(reb[now])-1)%2==1) + dp[wh][0],       go[now][1], wh);

            sum+=dp[wh][1]+1;
        }
    }
    else{
        dp[now][1]=inf;
    }
}

int fake_variable;

void build_ans(int now,bool is_root,int state,int& end_of_the_path)
{
    if (state==0){
        if (go[now][0]==inf){
            vector<int> guys=reb[now];
            if (len(guys)%2==1){
                ans[sz_ans++]={now,-12345};
                mark_cur(now,guys.back());
                build_ans(guys.back(),false,1,ans[sz_ans-1].sec);
                guys.pop_back();
            }
            for (int i=0;i<len(guys);i+=2){
                ans[sz_ans++]={-1234,-123};
                mark_cur(now,guys[i]);
                mark_cur(now,guys[i+1]);
                int buf=sz_ans-1;
                build_ans(guys[i],false,1,ans[buf].fir);
                build_ans(guys[i+1],false,1,ans[buf].sec);
            }
        }
        else{
            vector<int> guys;
            for (auto i:reb[now]){
                if (i!=go[now][0]){
                    guys.pb(i);
                }
            }
            build_ans(go[now][0],false,0,fake_variable);

            if (len(guys)%2==1){
                ans[sz_ans++]={now,-12345};
                mark_cur(now,guys.back());
                build_ans(guys.back(),false,1,ans[sz_ans-1].sec);
                guys.pop_back();
            }
            for (int i=0;i<len(guys);i+=2){
                ans[sz_ans++]={-1234,-123};
                mark_cur(now,guys[i]);
                mark_cur(now,guys[i+1]);
                int buf=sz_ans-1;
                build_ans(guys[i],false,1,ans[buf].fir);
                build_ans(guys[i+1],false,1,ans[buf].sec);
            }
        }
    }
    else{
        if (go[now][1]==inf){
            vector<int> guys=reb[now];
            if (len(guys)%2==1){
                mark_cur(now,guys.back());
                build_ans(guys.back(),false,1,end_of_the_path);
                guys.pop_back();
            }
            else{
                end_of_the_path=now;
            }
            for (int i=0;i<len(guys);i+=2){
                ans[sz_ans++]={-1234,-123};
                mark_cur(now,guys[i]);
                mark_cur(now,guys[i+1]);
                int buf=sz_ans-1;
                build_ans(guys[i],false,1,ans[buf].fir);
                build_ans(guys[i+1],false,1,ans[buf].sec);
            }
        }
        else{
            vector<int> guys;
            for (auto i:reb[now]){
                if (i!=go[now][1]){
                    guys.pb(i);
                }
            }
            build_ans(go[now][1],false,0,fake_variable);

            if (len(guys)%2==1){
                mark_cur(now,guys.back());
                build_ans(guys.back(),false,1,end_of_the_path);
                guys.pop_back();
            }
            else{
                end_of_the_path=now;
            }
            for (int i=0;i<len(guys);i+=2){
                ans[sz_ans++]={-1234,-123};
                mark_cur(now,guys[i]);
                mark_cur(now,guys[i+1]);
                int buf=sz_ans-1;
                build_ans(guys[i],false,1,ans[buf].fir);
                build_ans(guys[i+1],false,1,ans[buf].sec);
            }
        }
    }
}

void solve(int root)
{
    dfs2(root,1);
    build_ans(root,1,0,fake_variable);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,m;
    while (1){
        scanf("%d%d",&n,&m);
        if (n==0 && m==0){
            return 0;
        }

        for (int i=0;i<n;i++){
            reb[i].clear();
            reb2[i].clear();
            used[i]=0;
            marked_up[i]=0;
            dp[i][0]=dp[i][1]=inf;
            cur_in_dfs1[i]=0;

            reb_set[i].clear();
        }
        marked_cur.clear();
        sz_ans=0;

        while (m--){
            int s;
            scanf("%d",&s);
            int last=-1;
            for (int i=0;i<s;i++){
                int cur;
                scanf("%d",&cur);
                cur--;
//                cout<<"cur :: "<<cur<<"\n";

                if (i){
                    reb[cur].pb(last);
                    reb[last].pb(cur);
                }
                last=cur;
            }
        }

        dfs1(0);

        for (int i=0;i<n;i++){
            reb[i].clear();
        }
        for (int i=0;i<n;i++){
            if (predok[i]!=-1 && !marked_up[i]){
                reb[predok[i]].pb(i);
                reb_set[predok[i]].insert(i);
                reb_set[i].insert(predok[i]);
//                cout<<"reb_set :: "<<predok[i]<<"<->"<<i<<"\n";
            }
        }
        for (int i=0;i<n;i++){
            if (predok[i]==-1 || marked_up[i]){
                solve(i);
            }
        }
        for (int i=0;i<sz_ans;i++){
//            cout<<"ans :: "<<i.fir<<" "<<i.sec<<"\n";
            if (reb_set[ans[i].fir].count(ans[i].sec)){
//                cout<<"bad :: "<<i.fir<<" "<<i.sec<<"\n";
                bool ok=0;
                if (!ok){
                    for (auto wh:reb_set[ans[i].fir]){
                        if (!marked_cur.count(mp(ans[i].fir,wh))){
                            ans[i].fir=wh;
                            marked_cur.insert(mp(ans[i].fir,wh));
                            ok=1;
                            break;
                        }
                    }
                }
                if (!ok){
                    for (auto wh:reb_set[ans[i].sec]){
                        if (!marked_cur.count(mp(ans[i].sec,wh))){
                            ans[i].sec=wh;
                            marked_cur.insert(mp(ans[i].sec,wh));
                            ok=1;
                            break;
                        }
                    }
                }
                assert(ok);
            }
        }

        cout<<sz_ans<<"\n";
        for (int i=0;i<sz_ans;i++){
            cout<<ans[i].fir+1<<" "<<ans[i].sec+1<<"\n";
        }
    }
}

/*
3 1
3
3 2 3 1
 */