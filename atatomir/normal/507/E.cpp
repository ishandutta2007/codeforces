#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define maxN 100011
#define mp make_pair

typedef pair<long,long> mPair;

long n,m,i,cost,x,y,c,node,zeros;
vector<mPair> list[maxN];
queue<long> Q;
mPair dp[maxN];

bool inQueue[maxN];

vector<long> ans;
vector<pair<long,pair<long,long> > > mod;
bool vis[maxN];

bool better(mPair a,mPair b){
    if(a.first == b.first) return b.second > a.second;
    return b.first < a.first;
}

void Back(long node){
    vis[node] = true;
    for(long i=0;i<list[node].size();i++){
        long newNode = list[node][i].first,addOn=list[node][i].second;
        if(dp[newNode].first+1==dp[node].first &&
           dp[newNode].second+addOn==dp[node].second){
            ans.push_back(newNode);
            Back(newNode);
            return;
        }
    }
}

void RemoveEdge(long node,long node2){
    for(long i=0;i<list[node].size();i++){
        if(list[node][i].first == node2){
            if(list[node][i].second==0){
                mod.push_back(mp(node,mp(node2,1)));
            }

            list[node][i] = list[node][list[node].size()-1];
            list[node].pop_back();
            break;
        }
    }

    long tmp=node; node=node2; node2=tmp;

    for(long i=0;i<list[node].size();i++){
        if(list[node][i].first == node2){
            list[node][i] = list[node][list[node].size()-1];
            list[node].pop_back();
            break;
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> x >> y >> c;
        list[x].push_back(mp(y,c));
        list[y].push_back(mp(x,c));
        if(c) cost++; else zeros++;
    }

    dp[1] = mp(1,0); Q.push(1); inQueue[1] = true;
    while(!Q.empty()){
        node = Q.front(); Q.pop(); inQueue[node] = false;
        for(i=0;i<list[node].size();i++){
            long newNode = list[node][i].first,addOn=list[node][i].second;
            if((dp[newNode].first==0&&dp[newNode].second==0) || better(dp[newNode],mp(dp[node].first+1,dp[node].second+addOn))){
                dp[newNode] = mp(dp[node].first+1,dp[node].second+addOn);
                if(!inQueue[newNode]) {
                    Q.push(newNode);
                    inQueue[newNode] = true;
                }
            }
        }
    }

    ans.push_back(n);
    Back(n);

    for(i=0;i<ans.size()-1;i++) RemoveEdge(ans[i],ans[i+1]);
    for(i=1;i<=n;i++){
        for(long j=0;j<list[i].size();j++){
            if(list[i][j].first > i){
                if(list[i][j].second == 1){
                    mod.push_back(mp(i,mp(list[i][j].first,0)));
                }
            }
        }
    }

    cout << mod.size() << '\n';
    for(i=0;i<mod.size();i++) cout << mod[i].first << ' ' << mod[i].second.first << ' ' << mod[i].second.second << '\n';

    return 0;
}