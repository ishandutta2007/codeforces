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
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    string s;
    cin>>s;
    if (*max_element(all(s))=='0'){
        cout<<(len(s)>=2 ? a : 0ll)<<"\n";
        return;
    }
    int flags_border=0;
    vector<int> len00;
    int cnt11=0;
    int cnt00=0;
    int cnt0=0;
 
    for (int iter=0;iter<2;iter++){
        while (len(s)>=2 && s[len(s)-1]=='0' && s[len(s)-2]=='0'){
            cnt00++;
            s.pop_back();
        }
        if (s.back()=='0'){
            flags_border++;
            s.pop_back();
        }
        reverse(all(s));
    }
 
    for (int i=0;i<len(s);){
        int j=i;
        while (s[j]==s[i]){
            j++;
        }
        /// [i;j)
 
        int L=j-i;
 
        if (s[i]=='1'){
            cnt11+=L-1;
        }
        else{
            len00.pb(L);
        }
 
        i=j;
    }
 
    sort(all(len00));
    reverse(all(len00));
    while (!len00.empty() && len00.back()==1){
        cnt0++;
        len00.pop_back();
    }
 
    ll global_ans=0;
 
    for (int base_hod=0;base_hod<2;base_hod++){
        int buf_flags_border=flags_border;
        vector<int> buf_len00=len00;
        int buf_cnt00=cnt00;
        int buf_cnt0=cnt0;
        int buf_cnt11=cnt11;
 
        ll cur_ans=0;
 
        vector<int> last_greedy_moves;
 
        auto do_move_0=[&]()
        {
            if (!len00.empty()){
                cur_ans+=a;
                len00.back()-=1;
                if (len00.back()==1){
                    cnt0++;
                    len00.pop_back();
                    last_greedy_moves.pb(2);
                }
                else{
                    last_greedy_moves.pb(3);
                }
 
                return true;
            }
            else if (cnt00){
                cur_ans+=a;
                cnt00-=1;
 
                last_greedy_moves.pb(1);
 
                return true;
            }
            else if (cnt0){
                cur_ans-=c;
                cnt0-=1;
                cnt11++;
 
                return true;
            }
            else if (flags_border){
                cur_ans-=c;
                flags_border-=1;
 
                return true;
            }
 
            return false;
        };
 
        auto do_move_1=[&]()
        {
            if (cnt11==0 && !last_greedy_moves.empty()){
                if (last_greedy_moves.back()==1){
                    if (cnt0){
                        /// otkat
                        cur_ans-=a;
                        cnt00+=1;
                        last_greedy_moves.pop_back();
 
                        /// nakat
                        cur_ans-=c;
                        cnt0-=1;
                        cnt11++;
                    }
                }
                else if (last_greedy_moves.back()==2){
                    if (cnt0>1){
                        /// otkat
                        cur_ans-=a;
                        cnt0--;
                        len00.pb(1);
                        last_greedy_moves.pop_back();
 
                        /// nakat
                        cur_ans-=c;
                        cnt0-=1;
                        cnt11++;
                    }
                }
                else if (last_greedy_moves.back()==3){
                    if (cnt0){
                        /// otkat
                        cur_ans-=a;
                        len00.back()+=1;
                        last_greedy_moves.pop_back();
 
                        /// nakat
                        cur_ans-=c;
                        cnt0-=1;
                        cnt11++;
                    }
                }
            }
            if (cnt11){
                cur_ans+=b;
                cnt11--;
 
                return true;
            }
 
            return false;
        };
 
        int cur_hod=base_hod;
        while (1){
            if (cur_hod==0){
                if (!do_move_0()){
                    break;
                }
            }
            else{
                if (!do_move_1()){
                    break;
                }
            }
            global_ans=max(global_ans,cur_ans);
 
            cur_hod^=1;
        }
 
        flags_border=buf_flags_border;
        len00=buf_len00;
        cnt00=buf_cnt00;
        cnt0=buf_cnt0;
        cnt11=buf_cnt11;
    }
    cout<<global_ans<<"\n";
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