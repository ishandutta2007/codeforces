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

const int max_n = -1, inf = 1000111222;

bool a[110][100];

vector<vector<pii>> ans;

void do_op(vector<pii> op)
{
    for (auto i:op){
        a[i.fir][i.sec]^=1;
    }
    ans.pb(op);
}

bool is_in(int n,int m,int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

void solve_one(int n,int m,int x,int y)
{
    for (int dx=-1;dx<=1;dx+=2){
        for (int dy=-1;dy<=1;dy+=2){
            if (is_in(n,m,x+dx,y+dy)){
                vector<pii> op1;
                op1.pb(mp(x,y));
                op1.pb(mp(x+dx,y));
                op1.pb(mp(x,y+dy));

                vector<pii> op2;
                op2.pb(mp(x,y));
                op2.pb(mp(x+dx,y));
                op2.pb(mp(x+dx,y+dy));

                vector<pii> op3;
                op3.pb(mp(x,y));
                op3.pb(mp(x,y+dy));
                op3.pb(mp(x+dx,y+dy));

                do_op(op1);
                do_op(op2);
                do_op(op3);
                return;
            }
        }
    }
}

bool case1(int n,int m)
{
    int cnt1=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cnt1+=(a[i][j]==1);
        }
    }
    if (cnt1==0){
        return 1;
    }
    if (1){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]){
                    solve_one(n,m,i,j);
                }
            }
        }
    }
    return 0;
}

void do_all(int n,int m)
{
    if (case1(n,m)){
        return;
    }
}

void solve()
{
    ans.clear();

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int j=1;j<=m;j++){
            a[i][j]=(s[j-1]=='1');
        }
    }

    do_all(n,m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            assert(a[i][j]==0);
        }
    }

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        for (auto j:i){
            cout<<j.fir<<" "<<j.sec<<" ";
        }
        cout<<"\n";
    }

}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}