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

const int max_n = 1e4+10, inf = 1000111222;

const int max_log=30;

const bool debug=0;

int a[max_n];

int ask(int i,int j,int type)
{
    if (debug){
        if (type==0){
            return a[i]|a[j];
        }
        else{
            return a[i]&a[j];
        }
    }
    else{
        if (type==0){
            cout<<"or"<<" "<<i+1<<" "<<j+1<<"\n";
        }
        else{
            cout<<"and"<<" "<<i+1<<" "<<j+1<<"\n";
        }
        fflush(stdout);
        int res;
        cin>>res;
        fflush(stdout);
        return res;
    }
}

int ans[max_n];

int bit3[3][max_log];

bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}

void solve3()
{
    memset(bit3,-1,sizeof(bit3));
    for (int i=0;i<3;i++){
        int cur_or=ask(i,(i+1)%3,0);
        int cur_and=ask(i,(i+1)%3,1);

        for (int j=0;j<max_log;j++){
            if (get_bit(cur_and,j)){
                bit3[i][j]=1;
                bit3[(i+1)%3][j]=1;
            }
            if (!get_bit(cur_or,j)){
                bit3[i][j]=0;
                bit3[(i+1)%3][j]=0;
            }
        }
    }
    for (int j=0;j<max_log;j++){
        int any=-1;
        for (int i=0;i<3;i++){
            if (bit3[i][j]!=-1){
                any=bit3[i][j];
            }
        }
        assert(any!=-1);
        for (int i=0;i<3;i++){
            if (bit3[i][j]==-1){
                bit3[i][j]=any^1;
            }
        }
    }

    for (int i=0;i<3;i++){
        for (int j=0;j<max_log;j++){
            if (bit3[i][j]==1){
                ans[i]+=(1ll<<j);
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,k;
    cin>>n>>k;

    if (debug){
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
    }

    solve3();

    for (int i=3;i<n;i++){
        int cur_or=ask(0,i,0);
        int cur_and=ask(0,i,1);

        for (int j=0;j<max_log;j++){
            if (get_bit(cur_and,j)){
                ans[i]+=(1ll<<j);
            }
            else if (!get_bit(cur_or,j)){

            }
            else{
                if (!get_bit(ans[0],j)){
                    ans[i]+=(1ll<<j);
                }
                else{

                }
            }
        }
    }

    if (debug){
        for (int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    sort(ans,ans+n);
    cout<<"finish"<<" "<<ans[k-1]<<"\n";
    fflush(stdout);
}