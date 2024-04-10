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

const int max_n = -1, inf = 1000111222;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int A,B,AB,BA;
        cin>>A>>B>>AB>>BA;
        string s;
        cin>>s;
        int cnt_A=0;
        int cnt_B=0;
        for (auto i:s){
            if (i=='A'){
                cnt_A++;
            }
            else{
                cnt_B++;
            }
        }
        if (A+AB+BA!=cnt_A || B+AB+BA!=cnt_B){
            cout<<"NO"<<"\n";
            continue;
        }
        vector<int> gAB;
        vector<int> gABA;
        vector<int> gBA;
        vector<int> gBAB;
        for (int i=0;i+1<len(s);){
            if (s[i]==s[i+1]){
                i++;
                continue;
            }
            int j=i+1;
            while (j+1<len(s) && s[j+1]!=s[j]){
                j++;
            }
            /// [i;j]

            if (s[i]=='A'){
                if ((j-i+1)%2==0){
                    gAB.pb((j-i+1)/2);
                }
                else{
                    gABA.pb((j-i+1)/2);
                }
            }
            else{
                if ((j-i+1)%2==0){
                    gBA.pb((j-i+1)/2);
                }
                else{
                    gBAB.pb((j-i+1)/2);
                }
            }

            i=j+1;
        }

        sort(all(gAB));
        sort(all(gABA),greater<int>());
        sort(all(gBA),greater<int>());
        sort(all(gBAB),greater<int>());

        int greedy_AB=0;
        for (auto i:gAB){
            greedy_AB+=i;
//            LOG("AB",i);
        }
        for (auto i:gABA){
            greedy_AB+=i;
//            LOG("ABA",i);
        }
        for (auto i:gBA){
            greedy_AB+=i-1;
//            LOG("BA",i);
        }
        for (auto i:gBAB){
            greedy_AB+=i;
//            LOG("BAB",i);
        }

        if (greedy_AB<AB){
            cout<<"NO"<<"\n";
            continue;
        }
//        LOG(greedy_AB);
        int received_BA=0;
        vector<int> new_gBA;
        for (auto i:gBA){
            if (i!=1){
                new_gBA.pb(i);
            }
            else{
                received_BA++;
            }
        }
        gBA=new_gBA;
        while (greedy_AB>AB){
            if (!gBA.empty()){
                gBA.back()-=1;
                received_BA++;
                if (gBA.back()==1){
                    gBA.pop_back();
                    received_BA++;
                }

                greedy_AB--;
            }
            else if (!gABA.empty()){
                gABA.back()-=1;
                received_BA++;
                if (gABA.back()==0){
                    gABA.pop_back();
                }

                greedy_AB--;
            }
            else if (!gBAB.empty()){
                gBAB.back()-=1;
                received_BA++;
                if (gBAB.back()==0){
                    gBAB.pop_back();
                }

                greedy_AB--;
            }
            else if (!gAB.empty()){
                gAB.back()-=1;
                greedy_AB--;

                if (gAB.back()<=(greedy_AB-AB)){
                    greedy_AB-=gAB.back();
                    received_BA+=gAB.back();
                    gAB.pop_back();
                }
                else{
                    int can=greedy_AB-AB;
                    greedy_AB-=can;
                    received_BA+=can;
                }
            }
            else{
                assert(0);
            }
        }
//        LOG(received_BA);
        cout<<(received_BA>=BA ? "YES" : "NO")<<"\n";
    }
}