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
    string s;
    string t;
    cin>>s>>s>>t;
    for (auto& i:s){
        i-='0';
    }
    for (auto& i:t){
        i-='0';
    }
    int rev=0;
    int l=0,r=len(s)-1;
    vector<int> ans(0);
    for (int i=len(s)-1;i>=0;i--){
//        cout<<"kek :: "<<i<<" "<<rev<<" "<<(int)s[r]<<" "<<(int)t[i]<<"\n";
        if (i == 0){
            if ((s[r]^rev)!=t[i]){
                ans.push_back(1);
            }
            break;
        }
        if ((s[r]^rev)==t[i]){
            if (l<=r){
                r--;
            }
            else{
                r++;
            }
        }
        else if ((s[r]^rev)!=t[i]){
            int new_l;
            int new_r;
            if ((s[l]^rev)!=t[i]){
                ans.push_back(i+1);
                rev^=1;
            }
            else{
                ans.push_back(1);
                ans.push_back(i+1);
                rev^=1;
            }
            if (l<r){
                new_l=r;
                new_r=l+1;
            }
            else{
                new_l=r;
                new_r=l-1;
            }
            l=new_l;
            r=new_r;
        }
    }
    cout<<len(ans)<<" ";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
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