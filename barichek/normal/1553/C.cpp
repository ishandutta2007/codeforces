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

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int ans=10;
        string s;
        cin>>s;
        int cnt_bad=0;
        for (auto i:s){
            cnt_bad+=(i=='?');
        }
        for (int mask=0;mask<(1ll<<cnt_bad);mask++){
            int res1=0;
            int res2=0;
            int cur_id_in_mask=0;
            int rest1=5;
            int rest2=5;
            for (int i=0;i<10;i++){
                int cur_res=s[i]-'0';
                if (s[i]=='?'){
                    cur_res=get_bit(mask,cur_id_in_mask++);
                }

                if (i%2==0){
                    res1+=cur_res;
                }
                else{
                    res2+=cur_res;
                }

                if (i%2==0){
                    rest1--;
                }
                else{
                    rest2--;
                }

                auto check=[&]()
                {
                    if (res1+rest1<res2){
                        return 1;
                    }
                    if (res2+rest2<res1){
                        return 1;
                    }
                    return 0;
                };

                if (check()){
                    ans=min(ans,i+1);
                }
            }
        }
        cout<<ans<<"\n";
    }
}