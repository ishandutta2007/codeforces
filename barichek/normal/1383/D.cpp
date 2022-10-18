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

const int max_n = 250+10, inf = 1000111222;

int a[max_n][max_n];
bool is_max[2][max_n*max_n];
int ans[max_n][max_n];
vector<pii> closeds;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        int kek=0;
        for (int j=1;j<=m;j++){
            kek=max(kek,a[i][j]);
        }
        is_max[0][kek]=1;
    }
    for (int j=1;j<=m;j++){
        int kek=0;
        for (int i=1;i<=n;i++){
            kek=max(kek,a[i][j]);
        }
        is_max[1][kek]=1;
    }
    int x=0,y=0;
    vector<int> to_set(0);
    for (int i=n*m;i>=1;i--){
        if (is_max[0][i] && is_max[1][i]){
            x++;
            y++;
            closeds.pb(mp(x,y));
            ans[x][y]=i;
        }
        else if (is_max[0][i]){
            x++;
            closeds.pb(mp(x,y));
            ans[x][y]=i;
        }
        else if (is_max[1][i]){
            y++;
            closeds.pb(mp(x,y));
            ans[x][y]=i;
        }
        else{
            to_set.pb(i);
        }
    }

    reverse(all(closeds));
    for (auto i:closeds){
        int x=i.fir;
        int y=i.sec;
        for (int j=1;j<y;j++){
            if (ans[x][j]==0){
                ans[x][j]=to_set.back();
                to_set.pop_back();
            }
        }
        for (int i=1;i<x;i++){
            if (ans[i][y]==0){
                ans[i][y]=to_set.back();
                to_set.pop_back();
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}