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

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> used_in_second(n,0);
    vector<int> a(n,0);
    vector<int> pos_in_a(n,0);
    vector<int> b(k,0);

    for (auto& i:a){
        cin>>i;
        i--;
    }
    for (int i=0;i<len(a);i++){
        pos_in_a[a[i]]=i;
    }

    for (auto& i:b){
        cin>>i;
        i--;
        used_in_second[i]=1;
    }

    set<pii> s;
    for (int i=0;i<len(a);){
//        cout<<i<<" !!!\n";
        if (used_in_second[a[i]]){
            i++;
            continue;
        }
        int j=i;
        while (j+1<len(a) && !used_in_second[a[j+1]]){
            j++;
        }
        /// [i;j]

        s.insert(mp(i,j));

        i=j+1;
    }

    int ans=1;
    for (auto bb:b){
//        for (auto i:s){
//            cout<<"("<<i.fir<<","<<i.sec<<") ";
//        }
//        cout<<"\n";

        int pos=pos_in_a[bb];
        auto it2 = s.lower_bound(mp(pos,-1));
        auto it1=it2;
        it1--;

        if (it2==s.end() || it2->fir!=pos+1){
            if (it1->sec!=pos-1){
                ans=0;
                break;
            }
            auto buf=*it1;
            s.erase(it1);
            buf.sec=pos;
            s.insert(buf);
        }
        else if (it2==s.begin() || it1->sec!=pos-1){
            if (it2->fir!=pos+1){
                ans=0;
                break;
            }
            auto buf=*it2;
            s.erase(it2);
            buf.fir=pos;
            s.insert(buf);
        }
        else{
            auto buf1=*it1;
            auto buf2=*it2;
            s.erase(it1);
            s.erase(it2);
            s.insert(mp(buf1.fir,buf2.sec));
            ans=1ll*ans*2%998244353;
        }
    }
    cout<<ans<<"\n";
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