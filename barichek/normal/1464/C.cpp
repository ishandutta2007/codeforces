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

//bool can[15][1ll<<15];
//
//bool is_bit(int mask,int bit)
//{
//    return (mask>>bit)&1;
//}
//
//int rev_mask(int n,int mask)
//{
//    return ((1ll<<n)-1) ^ mask;
//}
//
//void build_can(int n)
//{
//    if (n==1){
//        can[1][1]=1;
//    }
//    else{
//        for (int m=1;m<n;m++){
//            for (int mask1=0;mask1<(1ll<<m);mask1++){
//                if (!can[m][mask1]){
//                    continue;
//                }
//                for (int mask2=0;mask2<(1ll<<(n-m));mask2++){
//                    if (!can[n-m][mask2]){
//                        continue;
//                    }
//                    can[n][rev_mask(m,mask1)^(mask2<<m)]=1;
//                }
//            }
//        }
//    }
//}

int cnt[1000];

void print_answer(string answer)
{
    cout<<answer<<"\n";
    exit(0);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    const int n=3;
//    for (int i=1;i<=n;i++){
//        build_can(i);
//    }
//    for (int i=0;i<(1ll<<n);i++){
//        if (is_bit(i,n-1) && !can[n][i]){
//            cout<<"can't :: ";
//            for (int j=0;j<n;j++){
//                cout<<is_bit(i,j);
//            }
//            cout<<"\n";
//        }
//        if (can[n][i]){
//            assert(is_bit(i,n-1) && !is_bit(i,n-2));
//        }
//        if (is_bit(i,n-1) && !is_bit(i,n-2)){
//            assert(can[n][i]);
//        }
//    }

    int n;
    ll t;
    cin>>n>>t;
    string s;
    cin>>s;
    if (len(s)==1){
        if ((1ll<<(s[0]-'a'))==t){
            print_answer("Yes");
        }
        else{
            print_answer("No");
        }
    }

    t-=(1ll<<(s.back()-'a'));
    s.pop_back();

    t+=(1ll<<(s.back()-'a'));
    s.pop_back();

    for (int i=0;i<len(s);i++){
        cnt[s[i]-'a']++;
    }

    for (int i=0;i<30;i++){
        t+=1ll*cnt[i]*(1ll<<i);
    }

    if (t%2==1){
        print_answer("No");
    }
    t/=2;

    for (int i=0;i<55;i++){
        if (t&(1ll<<i)){
            if (!cnt[i]){
                print_answer("No");
            }
            else{
                cnt[i]--;
            }
        }
        while (cnt[i]>=2){
            cnt[i]-=2;
            cnt[i+1]+=1;
        }
    }

    print_answer("Yes");
}