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

const int max_n = 64+2, inf = 1000111222;

pii edge[max_n][max_n];

const int max_row=2100; // grubo
const int max_col=256+2;

int gaus[max_row][max_col];
int b[max_row];

bool need_to_answer[max_col];

void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            edge[i][j]=mp(-2,-2);
        }
    }
    memset(gaus,0,sizeof(gaus));
    memset(b,0,sizeof(b));
    memset(need_to_answer,0,sizeof(need_to_answer));
    vector<pii> edges;
    for (int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;


        if (c!=-1){
            c--;
        }
        else{
            need_to_answer[i]=1;
        }

        edge[u][v]=edge[v][u]=mp(c,i);
        edges.pb(mp(u,v));
    }

    auto get_already=[&](int u,int v)
    {
        if (edge[u][v].fir<0){
            return 0;
        }
        return edge[u][v].fir;
    };


    int row=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (edge[i][j].fir!=-2 && edge[j][k].fir!=-2 && edge[i][k].fir!=-2){
                    assert(row<max_row);

                    int already_have=get_already(i,j)+get_already(j,k)+get_already(i,k);
                    already_have%=3;
                    if (edge[i][j].fir==-1){
                        gaus[row][edge[i][j].sec]=1;
                    }
                    if (edge[j][k].fir==-1){
                        gaus[row][edge[j][k].sec]=1;
                    }
                    if (edge[i][k].fir==-1){
                        gaus[row][edge[i][k].sec]=1;
                    }
//                    cout<<"I had :: "<<already_have<<"\n";
                    b[row]=(3-already_have)%3;

                    row++;
                }
            }
        }
    }


    int N=row;
    int M=m;
    /// solve gaus
    {
//        cout<<"gaus :: "<<"\n";
//        for (int i=0;i<N;i++){
//            for (int j=0;j<M;j++){
//                cout<<gaus[i][j]<<" ";
//            }
//            cout<<" = "<<b[i]<<"\n";
//        }
        vector<int> where (M, -1);
        for (int col=0, row=0; col<M && row<N; ++col) {
            int sel = row;
            for (int i=row; i<N; ++i)
                if (gaus[i][col])
                    sel = i;
            if (gaus[sel][col]==0)
                continue;
            for (int i=col; i<M; ++i)
                swap (gaus[sel][i], gaus[row][i]);
            swap(b[sel],b[row]);
            where[col] = row;

            if (gaus[row][col]==2){
                for (int j=col; j<M; ++j)
                    gaus[row][j] = gaus[row][j] * 2 % 3;
                b[row]=b[row] * 2 % 3;
            }

            for (int i=0; i<N; ++i)
                if (i != row && gaus[i][col]) {
                    int c=(gaus[i][col]==1 ? 1 : 2);
                    for (int j=col; j<M; ++j){
                        gaus[i][j] -= gaus[row][j] * c%3;
                        if (gaus[i][j]<0){
                            gaus[i][j]+=3;
                        }
                    }
                    b[i]-=b[row]*c%3;
                    if (b[i]<0){
                        b[i]+=3;
                    }
                }
            ++row;
        }

        auto set_edge_ans=[&](int edge_id,int value)
        {
            int u=edges[edge_id].fir;
            int v=edges[edge_id].sec;
//            cout<<"answer edge :: "<<u<<" "<<v<<" "<<value<<"\n";
            edge[u][v].fir=value;
            edge[v][u].fir=value;
        };

        for (int i=0; i<M; ++i)
            if (where[i] != -1)
                set_edge_ans(i, b[where[i]]);
        for (int i=0; i<M; ++i)
            if (where[i] == -1 && need_to_answer[i])
                set_edge_ans(i, 0);
    }


    bool flag_bad=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            for (int k=j+1;k<n;k++){
                if (edge[i][j].fir!=-2 && edge[j][k].fir!=-2 && edge[i][k].fir!=-2){
                    int already_have=get_already(i,j)+get_already(j,k)+get_already(i,k);
                    already_have%=3;
                    if (already_have!=0){
                        flag_bad=1;
//                        cout<<"bad :: "<<i<<" "<<j<<" "<<k<<" :: "<<already_have<<"\n";
                    }
                }
            }
        }
    }

    if (flag_bad){
        cout<<-1<<"\n";
    }
    else{
        for (auto i:edges){
            cout<<edge[i.fir][i.sec].fir+1<<" ";
        }
        cout<<"\n";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}