//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")

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

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
const ll inf=1e18+10;

///---program start---///

const int N=30000;

int get_magic_seq_req(int n,int step)
{
    int res=0;
    while (step){
        int base = (1ll<<(step-2));
        if (n/base==0){
            res+=0*base;
        }
        if (n/base==1){
            res+=2*base;
        }
        if (n/base==2){
            res+=3*base;
        }
        if (n/base==3){
            res+=1*base;
        }
        n%=base;
        step-=2;
    }
    return res;
}

//int get_magic_seq_req(int n,int step)
//{
////    cout<<"get_magic_req "<<n<<" "<<step<<"\n";
//    if (step==0){
//        return 0;
//    }
//    int base = (1ll<<(step-2));
//    if (n/base==0){
//        return 0*base+get_magic_seq_req(n%base, step-2);
//    }
//    if (n/base==1){
//        return 2*base+get_magic_seq_req(n%base, step-2);
//    }
//    if (n/base==2){
//        return 3*base+get_magic_seq_req(n%base, step-2);
//    }
//    if (n/base==3){
//        return 1*base+get_magic_seq_req(n%base, step-2);
//    }
//    assert(0);
//}

int get(int n)
{
    int n1 = n/3;
    int n2 = n%3;

    int step = 0;
    while (true){
        if (n1>=(1ll<<step)){
            n1-=(1ll<<step);
            step+=2;
        }
        else{
            break;
        }
    }
    int left_step = (1ll<<step);
    int right_step = 2 * left_step;

    int A=-1;
    int B=-1;
    int C=-1;

    A=left_step + n1;

    B=right_step + get_magic_seq_req(n1, step);

    C=A^B;

    return (n2==0?A:n2==1?B:C);
}

int max_bit(int a)
{
    for (int i=30;i>=0;i--){
        if (a&(1ll<<i)){
            return (1ll<<i);
        }
    }
}

void brute()
{
    set<int> used;
    for (int iter=0;iter<2000;iter++){
        for (int i=1;i<=N;i++){
            if (used.count(i)){
                continue;
            }
            for (int j=i+1;j<=N;j++){
                if (used.count(j)){
                    continue;
                }
                int k=i^j;
                if (used.count(k)){
                    continue;
                }
                if (max_bit(i)==i){
                    cout<<string(20,'-')<<"\n";
                }
//                cout<<i<<" "<<j<<" "<<k<<"\n";
//                cout<<"my_ans :: "<<get(iter*3+0)<<" "<<get(iter*3+1)<<" "<<get(iter*3+2)<<"\n";
                assert(i==get(iter*3+0));
                assert(j==get(iter*3+1));
                assert(k==get(iter*3+2));
                used.insert(i);
                used.insert(j);
                used.insert(k);
                goto label;
            }
        }
        assert(0);
        label:;
    }
}

signed main()
{
    #ifdef __APPLE__
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

//    brute();

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        n--;
        cout<<get(n)<<"\n";
    }
}