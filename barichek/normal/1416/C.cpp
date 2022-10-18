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

const int max_n = 3e5+10, inf = 1000111222;

struct node
{
    int p0,p1;
    int cnt;

    node()
    {
        p0=p1=0;
        cnt=0;
    }
};

int root=1;
node A[max_n*33];
int last_used=1;

int new_node()
{
    return ++last_used;
}

int a[max_n];
ll cost_if_set[33][2];

void add_number(int a)
{
    int cur=root;
    for (int i=30;i>=0;i--){
        if (a&(1ll<<i)){
            if (A[cur].p0){
                cost_if_set[i][0]+=A[A[cur].p0].cnt;
            }

            if (!A[cur].p1){
                A[cur].p1 = new_node();
            }
            cur=A[cur].p1;
            A[cur].cnt++;
        }
        else{
            if (A[cur].p1){
                cost_if_set[i][1]+=A[A[cur].p1].cnt;
            }

            if (!A[cur].p0){
                A[cur].p0 = new_node();
            }
            cur=A[cur].p0;
            A[cur].cnt++;
        }
    }
}

int n;

void calc_costs()
{
    for (int i=n;i>=1;i--){
        add_number(a[i]);
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    calc_costs();

    ll ans=0;
    int x=0;
    for (int i=0;i<31;i++){
        if (cost_if_set[i][0]<=cost_if_set[i][1]){
            ans+=cost_if_set[i][0];
        }
        else{
            x|=(1ll<<i);
            ans+=cost_if_set[i][1];
        }
    }
    cout<<ans<<" "<<x<<"\n";
}