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
 
char type[2*max_n];
int ans[2*max_n];
 
void do_merge(vector<int>& a,vector<int>& b)
{
    if (len(a)<len(b)){
        a.swap(b);
    }
    for (auto i:b){
        a.pb(i);
    }
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
    vector<pair<int,vector<int> > > q;
    for (int i=1;i<=2*n;i++){
        cin>>type[i];
        if (type[i]=='+'){
            q.pb(mp(-inf, vector<int>{i}));
        }
        else{
            int x;
            cin>>x;
//            cout<<"readed "<<x<<"\n";
            if (q.empty() || q.back().fir>=x){
                cout<<"NO"<<"\n";
                return 0;
            }
 
            int pos=q.back().sec.back();
            q.back().sec.pop_back();
            if (q.back().sec.empty()){
                q.pop_back();
            }
 
//            cout<<"ans["<<pos<<"] :: "<<x<<"\n";
            ans[pos]=x;
 
            vector<int> cur_poses;
            cur_poses.empty();
            while (!q.empty() && q.back().fir<=x){
                do_merge(cur_poses,q.back().sec);
                q.pop_back();
            }
            if (!cur_poses.empty()){
                q.pb(mp(x,cur_poses));
            }
        }
    }
 
    cout<<"YES"<<"\n";
    for (int i=1;i<=2*n;i++){
        if (type[i]=='+'){
            cout<<ans[i]<<" ";
        }
    }
    cout<<"\n";
}