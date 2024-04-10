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

const bool debug=0;

bool a[110][100];

vector<vector<pii>> ans;
int N,M;

void do_op(vector<pii> op)
{
//    cout<<"op :: ";
//    cout<<"\n";
//    for (auto i:op){
//        cout<<i.fir<<" "<<i.sec<<"\n";
//    }
//    cout<<"\n";

    for (auto i:op){
        a[i.fir][i.sec]^=1;
    }
    ans.pb(op);

//    cout<<"ans len :: "<<len(ans)<<"\n";

//    for (int i=1;i<=N;i++){
//        for (int j=1;j<=M;j++){
//            cout<<a[i][j];
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
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
    if (cnt1==1){
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

void do_2_rows(int n,int m,int r1,int r2)
{
    if (m==2){
        int cnt1=0;
        for (int j=1;j<=m;j++){
            cnt1+=(a[r1][j]==1);
            cnt1+=(a[r2][j]==1);
        }

        if (cnt1==1){
            for (int j=1;j<=m;j++){
                if (a[r1][j]==1){
                    solve_one(n,m,r1,j);
                }
                if (a[r2][j]==1){
                    solve_one(n,m,r2,j);
                }
            }
            return;
        }
    }
    for (int j=1;j<m;j++){
        if (a[r1][j] && !a[r2][j]){
            vector<pii> op;
            op.pb(mp(r1,j));
            op.pb(mp(r1,j+1));
            op.pb(mp(r2,j+1));

            do_op(op);
        }
        else if (!a[r1][j] && a[r2][j]){
            vector<pii> op;
            op.pb(mp(r2,j));
            op.pb(mp(r2,j+1));
            op.pb(mp(r1,j+1));

            do_op(op);
        }
        else if (a[r1][j] && a[r2][j]){
            vector<pii> op;
            op.pb(mp(r1,j));
            op.pb(mp(r2,j));

            if (a[r1][j+1]){
                op.pb(mp(r1,j+1));
            }
            else{
                op.pb(mp(r2,j+1));
            }

            do_op(op);
        }
    }

    if (a[r1][m] && a[r2][m]){
        vector<pii> op;
        op.pb(mp(r1,m));
        op.pb(mp(r2,m));
        op.pb(mp(r2,m-1));

        do_op(op);

        solve_one(n,m,r2,m-1);
    }
    else if (a[r1][m]){
        solve_one(n,m,r1,m);
    }
    else if (a[r2][m]){
        solve_one(n,m,r2,m);
    }
}

void do_all(int n,int m)
{
    if (case1(n,m)){
        return;
    }


    if (n&1){
        for (int j=1;j<=m;j++){
            if (a[n][j]){
                vector<pii> op;
                op.pb(mp(n,j));
                op.pb(mp(n-1,j));
                if (j==1){
                    op.pb(mp(n-1,j+1));
                }
                else{
                    op.pb(mp(n-1,j-1));
                }

                do_op(op);
            }
        }
    }
    for (int i=1;i+1<=n;i+=2){
        do_2_rows(n,m,i,i+1);
    }
}

void solve()
{
    ans.clear();

    int n,m;

    if (debug){
        n=rand()%8+2;
        m=rand()%8+2;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                a[i][j]=rand()%2;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    else{
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            string s;
            cin>>s;
            for (int j=1;j<=m;j++){
                a[i][j]=(s[j-1]=='1');
            }
        }
    }


    N=n;
    M=m;

    do_all(n,m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            assert(a[i][j]==0);
        }
    }
    assert(len(ans)<=n*m);

    cout<<len(ans)<<"\n";
    for (auto i:ans){
        for (auto j:i){
            cout<<j.fir<<" "<<j.sec<<" ";
        }
        cout<<"\n";
    }

}

/*

 11
00
00
11


11
11
10
01
00
10

*/

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}