//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

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

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
///#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

#define ar (int)(1e3+10)

int n,m,t;
ll dist[ar][ar];
string a[ar];

bool ok(int a,int b)
{
    return a>=0&&a<n&&b>=0&&b<m;
}

vector<pii> moves;

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    moves.pb(mp(0,1));
    moves.pb(mp(0,-1));
    moves.pb(mp(-1,0));
    moves.pb(mp(1,0));

    cin>>n>>m>>t;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            dist[i][j]=inf;
        }
    }
    queue<pii> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (auto wh:moves){
                int ii=i+wh.fir;
                int jj=j+wh.sec;
                if (ok(ii,jj) && a[ii][jj]==a[i][j]){
                    q.push(mp(i,j));
                    dist[i][j]=0;
                    break;
                }
            }
        }
    }

    while (!q.empty()){
        pii now=q.front();
        q.pop();
        for (auto wh:moves){
            int ii=now.fir+wh.fir;
            int jj=now.sec+wh.sec;
            if (ok(ii,jj) && dist[ii][jj]>dist[now.fir][now.sec]+1){
                q.push(mp(ii,jj));
                dist[ii][jj]=dist[now.fir][now.sec]+1;
            }
        }
    }

    while (t--){
        int x,y;
        ll p;
        cin>>x>>y>>p;
        x--;
        y--;
        int ans=a[x][y]-'0';
        ll time_when_captured = dist[x][y];
        ans^=(time_when_captured>p ? 0 : (p-time_when_captured)%2);
        cout<<ans<<"\n";
    }
}