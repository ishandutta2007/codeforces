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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c0=0,c1=0;
        for (auto i:s){
            if (i=='0'){
                c0++;
            }
            else{
                c1++;
            }
        }
        if (c0%2==1){
            cout<<"NO"<<"\n";
            continue;
        }
        int c_otk_0=c0/2;
        int c_zak_0=c0/2;
        int c_otk_1=n/2-c_otk_0;
        int c_zak_1=n-c_otk_0-c_zak_0-c_otk_1;
        string ans1="";
        string ans2="";
        int bal1=0;
        int bal2=0;
        bool flag=0;
        for (auto i:s){
            if (i=='0'){
                if (c_otk_0 == 0 || (c_zak_0 && bal1>=bal2)){
                    assert(c_zak_0);
                    c_zak_0--;
                    ans1+=")";
                    ans2+="(";
                    bal1--;
                    bal2++;
                }
                else{
                    assert(c_otk_0);
                    c_otk_0--;
                    ans1+="(";
                    ans2+=")";
                    bal1++;
                    bal2--;
                }
            }
            else{
                if (c_otk_1){
                    c_otk_1--;
                    ans1+="(";
                    ans2+="(";
                    bal1++;
                    bal2++;
                }
                else{
                    assert(c_zak_1);
                    c_zak_1--;
                    ans1+=")";
                    ans2+=")";
                    bal1--;
                    bal2--;
                }
            }

            if (bal1<0 || bal2<0){
                cout<<"NO"<<"\n";
                flag=1;
                break;
            }
        }
        if (!flag){
            assert(bal1==0 && bal2==0);
            cout<<"YES"<<"\n";
            cout<<ans1<<"\n";
            cout<<ans2<<"\n";
        }
    }
}