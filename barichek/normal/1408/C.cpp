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

void solve()
{
    int n,l;
    cin>>n>>l;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    pair<pii,ld> cur_left=mp(mp(1,1),0);
    pair<pii,ld> cur_right=mp(mp(n,1),l);
    ld ans=0;
    while (1){
//        cout<<ans<<" "<<cur_left.sec<<" "<<cur_right.sec<<"\n";
        if (cur_left.fir.fir == cur_right.fir.fir+1){
            ans+=(cur_right.sec-cur_left.sec)/ld(cur_left.fir.sec + cur_right.fir.sec);
            break;
        }
//        cout<<"time left right :: "<<(a[cur_left.fir.fir] - cur_left.sec)/(ld)cur_left.fir.sec<<"   "<< (cur_right.sec - a[cur_right.fir.fir])/(ld)cur_right.fir.sec<<"\n";
        bool is_left_will_be_faster = (a[cur_left.fir.fir] - cur_left.sec)/(ld)cur_left.fir.sec < (cur_right.sec - a[cur_right.fir.fir])/(ld)cur_right.fir.sec;
        if (is_left_will_be_faster){
            ld cur_time = (a[cur_left.fir.fir] - cur_left.sec)/(ld)cur_left.fir.sec;
//            cout<<"left cur_time :: "<<cur_time<<"\n";
            ans+=cur_time;
            cur_left.sec = a[cur_left.fir.fir];
            cur_left.fir.fir++;
            cur_left.fir.sec++;

            cur_right.sec-=cur_time*cur_right.fir.sec;
        }
        else{
            ld cur_time = (cur_right.sec - a[cur_right.fir.fir])/(ld)cur_right.fir.sec;
//            cout<<"rigth cur_time :: "<<cur_time<<"\n";
            ans+=cur_time;
            cur_right.sec = a[cur_right.fir.fir];
            cur_right.fir.fir--;
            cur_right.fir.sec++;

            cur_left.sec+=cur_time*cur_left.fir.sec;
        }
    }
    cout<<fixed<<setprecision(20)<<ans<<"\n";
//    cout<<"-----"<<"\n";
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