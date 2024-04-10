#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")

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

const int max_n = 1e6+10, inf = 1000111222;

const ll infll=1ll*inf*inf;

const int max_log=61;

ll a[max_n];
ll mn[max_n];
ll mx[max_n];

ll ans;

int cnt[max_log];

int get_bit_cnt(ll a)
{
    return __builtin_popcountll(a);
}

void solve_internal(int l,int r,int m,bool min_strogo_left)
{
//    cout<<"i am in :: ";
//    for (int i=l;i<=m;i++){
//        cout<<a[i]<<" ";
//    }
//    cout<<" | ";
//    for (int i=m+1;i<=r;i++){
//        cout<<a[i]<<" ";
//    }
//    cout<<"\n";
//    cout<<"min_strogo_left :: "<<min_strogo_left<<"\n";

    for (int i=m;i>=l;i--){
        mn[i]=min(i==m ? infll : mn[i+1], a[i]);
        mx[i]=max(i==m ? -infll : mx[i+1], a[i]);
    }
    for (int i=m+1;i<=r;i++){
        mn[i]=min(i==m+1 ? infll : mn[i-1], a[i]);
        mx[i]=max(i==m+1 ? -infll : mx[i-1], a[i]);
    }

    {
        /// min strogo??? left, max nestrogo left
        int p=m+1;
        for (int i=m;i>=l;i--){
            while (p<=r && (min_strogo_left ? mn[p]>mn[i] : mn[p]>=mn[i]) && mx[p]<=mx[i]){
                p++;
            }
//            cout<<"p mx[p] :: "<<p<<" "<<mx[p]<<"\n";
//            cout<<"m+1 :: "<<m+1<<"\n";
//            cout<<"answer here :: "<<ans<<"\n";
            if (__builtin_popcountll(mn[i])==__builtin_popcountll(mx[i])){
                ans+=p-(m+1);
            }

//            cout<<"answer 1 after "<<a[i]<<" :: "<<ans<<"\n";
        }
    }

    {
        /// min strogo??? left, max strogo right
        int p1=m+1;
        int p2=m+1;
        for (int i=m;i>=l;i--){
            while (p2<=r && (min_strogo_left ? mn[p2]>mn[i] : mn[p2]>=mn[i])){
                cnt[get_bit_cnt(mx[p2++])]++;
            }
            while (p1<p2 && mx[p1]<=mx[i]){
                cnt[get_bit_cnt(mx[p1++])]--;
            }
            ans+=cnt[get_bit_cnt(mn[i])];

//            cout<<"answer 2 after "<<a[i]<<" :: "<<ans<<"\n";
        }

        memset(cnt,0,sizeof(cnt));
    }
}

void solve(int l,int r)
{
    if (l==r){
        ans++;
        return;
    }

//    cout<<"["<<l<<";"<<r<<"] :: "<<ans<<"\n";

    int m=(l+r)/2;
    solve(l,m);
    solve(m+1,r);

    solve_internal(l,r,m,1);
//    cout<<"["<<l<<";"<<r<<"] :: "<<ans<<"\n";
    reverse(a+l,a+r+1);
    if ((r-l+1)%2==1){
        m=(l+r-1)/2;
    }
    solve_internal(l,r,m,0);
    reverse(a+l,a+r+1);

//    cout<<"["<<l<<";"<<r<<"] :: "<<ans<<"\n";
}

int get_naive(int n)
{
    int res=0;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            ll mn=*min_element(a+i,a+j+1);
            ll mx=*max_element(a+i,a+j+1);
            if (get_bit_cnt(mn)==get_bit_cnt(mx)){
                res++;
            }
        }
    }
    return res;
}

const bool debug=0;
const bool naive=0;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    start_of_program:;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    if (debug){
        n=1e6;
        for (int i=0;i<n;i++){
            a[i]=rand()%100;
        }
//        cout<<"test :: "<<"\n";
//        cout<<n<<"\n";
//        for (int i=0;i<n;i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<"\n";
    }
    else{
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
    }
    ans=0;
    solve(0,n-1);
    cout<<ans<<"\n";

    if (naive){
        if (ans!=get_naive(n)){
            cout<<"FOUND BAD"<<"\n";
            cout<<"naive :: "<<get_naive(n)<<"\n";
            exit(1);
        }
        cout<<"naive :: "<<get_naive(n)<<"\n";
    }

    if (debug && naive){
        goto start_of_program;
    }
}