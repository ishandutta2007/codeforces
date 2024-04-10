#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<pii,int>               piii;
typedef pair<pll,ll>                plll;
typedef pair<pdd,double>            pddd;
typedef pair<pld,ld>                pldd;
typedef vector<int>                 vi;
typedef vector<ll>                  vll;
typedef vector<double>              vd;
typedef vector<ld>                  vld;
typedef vector<pii>                 vpii;
typedef vector<pll>                 vpll;
typedef vector<pdd>                 vpdd;
typedef vector<pld>                 vpld;
typedef vector<piii>                vpiii;
typedef vector<plll>                vplll;
typedef vector<pddd>                vpddd;
typedef vector<pldd>                vpldd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define pb                          push_back
#define ppb                         pop_back
#define pf                          push_front
#define ppf                         pop_front
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

bool see[20002];
int bfs(int x,int y)
{
    queue<int> q;
    q.push(x);
    see[x]=true;

    map<int,int> mp;
    mp[x]=0;
    while(true)
    {
        int v=q.front();
        q.pop();

        if(v==y)
        {
            return mp[y];
        }

        if(v<y && !see[v*2])
        {
            q.push(v*2);
            mp[v*2]=mp[v]+1;
            see[v*2]=true;
        }

        if(v-1>=0 && !see[v-1])
        {
            q.push(v-1);
            mp[v-1]=mp[v]+1;
            see[v-1]=true;
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    cout << bfs(n,m);

    return 0;
}