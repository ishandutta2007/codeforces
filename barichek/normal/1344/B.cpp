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
#define int long long

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

string a[arr];
bool use[ar][ar];
int cnt1[arr];
int cnt2[arr];
vector<pii> moves;
int n,m;

bool ok(pii pos)
{
    return pos.fir>=0&&pos.sec>=0&&pos.fir<n&&pos.sec<m;
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    moves.pb(mp(-1,0));
    moves.pb(mp(+1,0));
    moves.pb(mp(0,-1));
    moves.pb(mp(0,+1));

    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
        for (int j=0;j<m;j++){
            if (a[i][j]=='#'){
                cnt1[i]++;
                cnt2[j]++;
            }
        }
    }
    for (int i=0;i<n;i++){
        int state = 0;
        for (int j=0;j<m;j++){
            if (state==0 && a[i][j]=='#'){
                state=1;
            }
            elif (state==1 && a[i][j]=='.'){
                state=2;
            }
            elif (state==2 && a[i][j]=='#'){
                state=3;
            }
        }
        if (state==3){
            cout<<-1<<"\n";
            return 0;
        }
    }
    for (int j=0;j<m;j++){
        int state = 0;
        for (int i=0;i<n;i++){
            if (state==0 && a[i][j]=='#'){
                state=1;
            }
            elif (state==1 && a[i][j]=='.'){
                state=2;
            }
            elif (state==2 && a[i][j]=='#'){
                state=3;
            }
        }
        if (state==3){
            cout<<-1<<"\n";
            return 0;
        }
    }
    int cnt1_zero=0;
    int cnt2_zero=0;
    for (int i=0;i<n;i++){
        if (cnt1[i]==0){
            cnt1_zero++;
        }
    }
    for (int j=0;j<m;j++){
        if (cnt2[j]==0){
            cnt2_zero++;
        }
    }
    if (cnt1_zero == 0 && cnt2_zero != 0){
        cout<<-1<<"\n";
        return 0;
    }
    if (cnt1_zero != 0 && cnt2_zero == 0){
        cout<<-1<<"\n";
        return 0;
    }
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]=='#' && !use[i][j]){
                ans++;

                queue<pii> q;
                use[i][j]=1;
                q.push(mp(i,j));
                while (!q.empty()){
                    pii now=q.front();
                    q.pop();
                    for (auto wh:moves){
                        pii to = mp(now.fir+wh.fir,now.sec+wh.sec);
                        if (ok(to) && !use[to.fir][to.sec] && a[to.fir][to.sec] == '#'){
                            use[to.fir][to.sec]=1;
                            q.push(to);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}