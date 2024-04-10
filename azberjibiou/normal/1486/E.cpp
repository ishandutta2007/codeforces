#include <bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int mxN=100100;
const ll INF=1000000000000000001;
typedef struct cmp1{
    bool operator()(const pll a, const pll b) const{
        return a.sec>b.sec;
    }
}cmp1;
int N, M;
ll dis[101*mxN];
priority_queue <pll, vector<pll>, cmp1> pq;
bool Chk[101*mxN];
vector <int> v[101*mxN];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=1;i<=101*(N+1);i++)   dis[i]=INF;
    for(int i=1;i<=101*(N+1);i++)   Chk[i]=true;
    for(int i=0;i<M;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[101*a].push_back(101*b+c);
        v[101*b+50+c].push_back(101*a);
        v[101*b].push_back(101*a+c);
        v[101*a+50+c].push_back(101*b);
        Chk[101*a]=Chk[101*b]=Chk[101*a+c]=Chk[101*b+c]=Chk[101*a+50+c]=Chk[101*b+50+c]=false;
    }
    pq.push({101, 0});
    dis[101]=0;
    while(!pq.empty())
    {
        while(!pq.empty() && Chk[pq.top().fir]) pq.pop();
        if(pq.empty())  break;
        int now=pq.top().fir;
        pq.pop();
        Chk[now]=true;
        for(int nxt : v[now])
        {
            if(Chk[nxt])    continue;
            if(dis[nxt]>dis[now])
            {
                dis[nxt]=dis[now];
                pq.push({nxt, dis[nxt]});
            }
        }
        if(now%101==0)   continue;
        if(now%101>=51)  continue;
        for(int i=1;i<=50;i++)
        {
            int nxt=now-now%101+i+50;
            if(Chk[nxt])    continue;
            if(dis[nxt]>dis[now]+(i+now%101)*(i+now%101))
            {
                dis[nxt]=dis[now]+(i+now%101)*(i+now%101);
                pq.push({nxt, dis[nxt]});
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(dis[i*101]==INF)  cout << -1 << " ";
        else    cout << dis[i*101] << " ";
    }
}