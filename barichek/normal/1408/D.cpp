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

const int max_n = 2000+10, inf = 1000111222;

const int max_X = 2e6+10;

int p[max_n];

vector<int> vh[max_X];

int ans_value[max_n];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int n,m;
    cin>>n>>m;
    vector<pii> A,B;
    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        A.pb(mp(a,b));
    }
    for (int i=1;i<=m;i++){
        int c,d;
        cin>>c>>d;
        B.pb(mp(c,d));
    }

    sort(all(B));
    vector<pii> new_B;
    for (auto i:B){
        while (!new_B.empty() && new_B.back().sec<=i.sec){
            new_B.pop_back();
        }
        new_B.pb(i);
    }
    B=new_B;

    set<pii> cur_ans;
    for (int i=0;i<len(A);i++){
        ans_value[i]=0;
        p[i]=len(B);
        for (int j=len(B)-1;j>=0;j--){
            if (B[j].fir>=A[i].fir){
                if (B[j].sec>=A[i].sec){
                    ans_value[i]=B[j].sec-A[i].sec+1;
//                    cout<<"vh of :: "<<B[j].fir-A[i].fir+1<<" !!!\n";
                    vh[B[j].fir-A[i].fir+1].pb(i);
                    p[i]=j;
                }
            }
        }
//        cout<<"start ans_value["<<i<<"] :: "<<ans_value[i]<<"\n";
        cur_ans.insert(mp(ans_value[i],i));
    }
    auto process=[&](int X,int i)
    {
        cur_ans.erase(mp(ans_value[i],i));

        while (p[i]!=len(B) && B[p[i]].fir<A[i].fir+X){
            p[i]++;
        }

        if (p[i]==len(B) || B[p[i]].sec<A[i].sec){
            ans_value[i]=0;
        }
        else{
            ans_value[i]=B[p[i]].sec-A[i].sec+1;
        }

//        cout<<"p["<<i<<"] :: "<<p[i]<<"\n";
//        cout<<A[i].fir<<" "<<A[i].sec<<" "<<B[p[i]].fir<<" "<<B[p[i]].sec<<"\n";
//        cout<<"ans_value["<<i<<"] :: "<<ans_value[i]<<"\n";

        cur_ans.insert(mp(ans_value[i],i));
    };
    int ans=2*max_X;
    for (int X=0;X<max_X;X++){
        for (auto i:vh[X]){
            process(X,i);
        }
//        cout<<"x :: "<<X<<"\n";
//        cout<<"p :: "<<p[0]<<" "<<p[1]<<"\n";
//        cout<<"ans :: "<<X<<" "<<cur_ans.rbegin()->fir<<"\n";
        ans=min(ans,X+cur_ans.rbegin()->fir);
    }
    cout<<ans<<"\n";
}