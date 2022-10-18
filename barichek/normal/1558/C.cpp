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

const int max_n = 3000+10, inf = 1000111222;

int a[max_n];

vector<int> ans;

void do_op(int prefix)
{
    ans.pb(prefix);
    reverse(a+1,a+prefix+1);
}

int find_pos(int val)
{
    for (int i=1;;i++){
        if (a[i]==val){
            return i;
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        ans.clear();

        int n;
        cin>>n;
        bool ok=0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            if (a[i]%2!=i%2){
                ok=1;
            }
        }
        if (ok){
            cout<<-1<<"\n";
            continue;
        }

        for (int i=n;i>1;i-=2){
            int nine=i;
            int eight=i-1;

            // 1
            {
                int pos=find_pos(nine);
                if (pos!=1){
                    do_op(pos);
                }
            }
            // 2
            {
                int pos=find_pos(eight);
                do_op(pos-1);
            }
            // 3
            {
                int pos=find_pos(eight);
                do_op(pos+1);
            }
            // 4
            {
                int pos=find_pos(nine);
                do_op(pos);
            }
            // 5
            {
                do_op(i);
            }
        }

        cout<<len(ans)<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";

        for (int i=1;i<=n;i++){
            assert(a[i]==i);
        }
    }
}