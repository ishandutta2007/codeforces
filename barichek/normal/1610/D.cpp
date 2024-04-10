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

const int max_n = 2e5+10, inf = 1000111222;

const int md=1e9+7;

int pw2[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pw2[0]=1;
    for (int i=1;i<max_n;i++){
        pw2[i]=pw2[i-1]+pw2[i-1];
        if (pw2[i]>=md){
            pw2[i]-=md;
        }
    }

    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for (int s=0;s<30;s++){
        int cnt_s=0;
        int cnt_bigger_s=0;
        for (auto i:a){
            if (i%(1ll<<s)==0){
                if (i%(1ll<<(s+1))==0){
                    cnt_bigger_s++;
                }
                else{
                    cnt_s++;
                }
            }
        }

//        cout<<s<<" "<<cnt_s<<" "<<cnt_bigger_s<<"\n";

        int cur_ans_s=0;
        if (s==0){
            cur_ans_s=pw2[cnt_s]-1;
            if (cur_ans_s<0){
                cur_ans_s+=md;
            }
        }
        else{
            if (cnt_s==0){
                cur_ans_s=0;
            }
            else{
                cur_ans_s=pw2[cnt_s-1]-1;
                if (cur_ans_s<0){
                    cur_ans_s+=md;
                }
            }
        }

//        cout<<"cur_ans_s :: "<<cur_ans_s<<"\n";

        cur_ans_s=1ll*cur_ans_s*pw2[cnt_bigger_s]%md;

        ans+=cur_ans_s;
        if (ans>=md){
            ans-=md;
        }
    }

    cout<<ans<<"\n";
}