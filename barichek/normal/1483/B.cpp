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

const int max_n = 1e5+10, inf = 1000111222;

int a[max_n];

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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int t;
    scanf("%d",&t);
    while (t--){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if (n==1){
            if (a[0]==1){
                cout<<"1 1"<<"\n";
            }
            else{
                cout<<"0"<<"\n";
            }
            continue;
        }
        set<int> alive_poses;
        set<int> gcd_1_poses;
        for (int i=0;i<n;i++){
            alive_poses.insert(i);
            if (gcd(a[i],a[(i+1)%n])==1){
                gcd_1_poses.insert(i);
            }
        }

        auto my_next=[&](auto it)
        {
            if (next(it)==alive_poses.end()){
                return alive_poses.begin();
            }
            else{
                return next(it);
            }
        };

        vector<int> ans;
        int cur=0;
        while (!gcd_1_poses.empty()){
            auto it=gcd_1_poses.lower_bound(cur);
            if (it==gcd_1_poses.end()){
                it=gcd_1_poses.begin();
            }

            int pos=*it;

            auto it1=alive_poses.lower_bound(pos);
            auto it2=my_next(it1);
            auto it3=my_next(it2);

            ans.pb(*it2);
            cur=*it2;
            gcd_1_poses.erase(*it1);
            gcd_1_poses.erase(*it2);

            alive_poses.erase(it2);

            if (it1!=it3){
                if (gcd(a[*it1],a[*it3])==1){
                    gcd_1_poses.insert(*it1);
                }
            }
            else{
                if (a[*it1]==1){
                    ans.pb(*it1);
                }
            }
        }

        cout<<len(ans);
        for (auto i:ans){
            cout<<" "<<i+1;
        }
        cout<<"\n";
    }
}