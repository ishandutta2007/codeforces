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

const int max_n = 4e5+10, inf = 1000111222;
const int md = 998244353;

int f[max_n];

void upd(int pos,int val)
{
    for (int i=pos;i<max_n;i|=i+1){
        f[i]+=val;
        if (f[i]>=md){
            f[i]-=md;
        }
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=i+1,i--){
        res+=f[i];
        if (res>=md){
            res-=md;
        }
    }
    return res;
}

void f_upd(int l,int r,int val)
{
    upd(l,+val);
    upd(r+1,val==0 ? 0 : md-val);
}

int f_get(int pos)
{
    return get(pos);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    vector<pair<pii,int>> v;
    vector<int> vh;
    vh.pb(0);
    for (int i=0;i<n;i++){
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        v.pb(mp(mp(x,y),s));
        vh.pb(x);
        vh.pb(y);
    }
    sort(all(vh));
    vh.erase(unique(all(vh)),vh.end());
    int ans=0;
    for (int i=len(vh)-1;i>0;i--){
        if (!v.empty() && v.back().fir.fir==vh[i]){
            int cur=f_get(i);
            cur+=v.back().sec;
            if (cur==md){
                cur=0;
            }
            int y_to_push=lower_bound(all(vh),v.back().fir.sec)-vh.begin();
//            cout<<i<<" :: "<<vh[i]<<" "<<cur<<"\n";
            ans+=1ll*cur*(v.back().fir.fir-v.back().fir.sec)%md;
            ans%=md;
//            cout<<"push :: "<<y_to_push<<" "<<i<<" :: "<<cur<<"\n";
            f_upd(y_to_push,i,cur);
            v.pop_back();
        }
    }
    cout<<(ans+vh.back()+1)%md<<"\n";
}