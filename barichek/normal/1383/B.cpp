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
map<pair<pii,pii>,bool> win1_dp;

bool win1(int cnt1,int cnt0,int val1,int val2)
{
//    cout<<"win1 :: "<<cnt1<<" "<<cnt0<<" "<<val1<<" "<<val2<<"\n";
    if (cnt1+cnt0==0){
        return val1>val2;
    }
    if (win1_dp.count(mp(mp(cnt1,cnt0),mp(val1,val2)))){
        return win1_dp[mp(mp(cnt1,cnt0),mp(val1,val2))];
    }
    bool res=0;
    if (cnt1>0){
        if (!win1(cnt1-1,cnt0,val2,val1^1)){
            res=1;
        }
    }
    if (cnt0>0){
        if (!win1(cnt1,cnt0-1,val2,val1)){
            res=1;
        }
    }
    win1_dp[mp(mp(cnt1,cnt0),mp(val1,val2))]=res;
    return res;
}

void solve()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        ans^=a[i];
    }
    int cnt1=-1;
    int cnt0=-1;
    for (int i=32;i>=0;i--){
        if (ans&(1ll<<i)){
            cnt0=0;
            cnt1=0;
            for (int j=0;j<n;j++){
                if (a[j]&(1ll<<i)){
                    cnt1++;
                }
                else{
                    cnt0++;
                }
            }
            break;
        }
    }
    if (cnt0==-1){
        cout<<"DRAW"<<"\n";
    }
//    else if (win1(cnt1,cnt0,0,0)){
    else if (cnt1%4==1 || cnt0%2==1){
        cout<<"WIN"<<"\n";
    }
    else{
        cout<<"LOSE"<<"\n";
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

//    for (int i=0;i<=1000;i++){
//        bool type01=1;
//        bool type1=1;
//        for (int j=0;j<=1000;j++){
//            if (win1(i,j,0,0)!=j%2){
//                type01=0;
//            }
//            if (win1(i,j,0,0)!=1){
//                type1=0;
//            }
//        }
//        if (type1){
//            cout<<i<<" !!\n";
//        }
////        cout<<i<<" "<<type01<<" "<<type1<<"\n";
//        assert(type01 ^ type1);
//    }

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}