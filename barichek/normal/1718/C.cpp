//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4")

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

#if __APPLE__
#define D for (bool _FLAG = true; _FLAG; _FLAG = false)
#define LOG(...) print(#__VA_ARGS__" ::", __VA_ARGS__) << endl
template <class ...Ts> auto &print(Ts ...ts) { return ((cerr << ts << " "), ...); }
#else
#define D while (false)
#define LOG(...)
#endif

const int max_n = 2e5+10, inf = 1000111222;

const bool debug = 0;

const int max_d = 200;

int a[max_n];
int in_cycle[max_n][max_d];

bool is_prime[max_n];

bool used[max_n];
bool used_g[max_n];

int gcd(int a,int b)
{
    while (a&&b){
        if (a>=b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return a+b;
}

void solve()
{
    int n,q;
    if (debug){
        n=2e5;
        q=2e5;
    }
    else{
        cin>>n>>q;
    }
    for (int i=0;i<n;i++){
        if (debug){
            a[i]=rand()%10000;
        }
        else{
            cin>>a[i];
        }
    }

    for (int i=1;i<=n;i++){
        used_g[i]=0;
    }
    vector<pair<ll,int>> cycles_cost_vec;
    multiset<ll> cycles_cost_set;
    int last_id=-1;
    for (int d=max(1,(n-1)/2);d<n;d++){
        int g=gcd(d,n);
        if (!used_g[g] && is_prime[n/g]){
            last_id++;

            used_g[g]=1;
            for (int i=0;i<n;i++){
                used[i]=0;
            }
            for (int i=0;i<n;i++){
                if (!used[i]){
                    cycles_cost_vec.pb(mp(0,0));
                    int cur=i;
                    while (!used[cur]){
                        cycles_cost_vec.back().fir+=a[cur];
                        cycles_cost_vec.back().sec++;
                        used[cur]=1;
                        in_cycle[cur][last_id]=len(cycles_cost_vec)-1;
                        cur+=d;
                        if (cur>=n){
                            cur-=n;
                        }
                    }
                    cycles_cost_set.insert(cycles_cost_vec.back().fir*(n/cycles_cost_vec.back().sec));
                }
            }
        }
    }
    cout<<*cycles_cost_set.rbegin()<<"\n";
    while (q--){
        int p,x;
        if (debug){
            p=rand()%n+1;
            x=rand()%10000;
        }
        else{
            cin>>p>>x;
        }
        p--;
        for (int cc=0;cc<=last_id;cc++){
            int c=in_cycle[p][cc];
            cycles_cost_set.erase(cycles_cost_set.find(cycles_cost_vec[c].fir*(n/cycles_cost_vec[c].sec)));
            cycles_cost_vec[c].fir+=x-a[p];
            cycles_cost_set.insert(cycles_cost_vec[c].fir*(n/cycles_cost_vec[c].sec));
        }
        a[p]=x;
        cout<<*cycles_cost_set.rbegin()<<"\n";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i=0;i<max_n;i++){
        is_prime[i]=1;
    }

    for (int i=2;i<max_n;i++){
        if (is_prime[i]){
            for (int j=2*i;j<max_n;j+=i){
                is_prime[j]=0;
            }
        }
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    if (debug){
        test=1;
    }
    else{
        cin>>test;
    }
    while (test--){
        solve();
    }
}