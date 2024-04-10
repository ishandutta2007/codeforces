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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        bool any_win=0;

        vector<int> a;
        int cnt=0;
        for (auto i:s){
            if (i=='W'){
                any_win=1;
                a.pb(cnt);
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        a.pb(cnt);
        cnt=0;

        int start_ans=0;
        for (int i=0;i<len(s);i++){
            if (s[i]=='W'){
                start_ans++;
                if (i && s[i-1]=='W'){
                    start_ans++;
                }
            }
        }

        if (!any_win){
            int ans = (k==0 ? 0 : 1 + (k-1)*2);
            cout<<ans<<"\n";
        }
        else{
            int L=a.front();
            int R=a.back();

            if (L>R){
                swap(L,R);
            }

            a.pop_back();
            reverse(all(a));
            a.pop_back();
            reverse(all(a));

            int ans=start_ans;
            sort(all(a));
            reverse(all(a));
            while (!a.empty() && a.back()==0){
                a.pop_back();
            }
            while (k){
                if (a.empty()){
                    if (L){
                        ans+=2;
                        L--;
                    }
                    else if (R){
                        ans+=2;
                        R--;
                    }
                }
                else{
                    ans+=2;
                    a.back()--;
                    if (a.back()==0){
                        ans++;
                        a.pop_back();
                    }
                }
                k--;
            }

            cout<<ans<<"\n";
        }

        /*
         ! Noone

         l => (l-1)*2 + 3


         +1 LWL
         +2 WWL LWW
         +3 WWW
         */
    }
}