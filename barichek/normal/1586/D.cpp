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

    int n;
    cin>>n;
    vector<int> reses1(n+1,-1);
    vector<int> reses2(n+1,-1);
    vector<int> ans(n+1,-1);
    for (int i=1;i<=n;i++){
        cout<<"?";
        for (int j=1;j<=n;j++){
            if (i==j){
                cout<<" "<<1;
            }
            else{
                cout<<" "<<2;
            }
        }
        cout<<"\n";
        fflush(stdout);

        int res;
        cin>>res;
        reses1[i]=res;
    }
    for (int i=1;i<=n;i++){
        cout<<"?";
        for (int j=1;j<=n;j++){
            if (i==j){
                cout<<" "<<2;
            }
            else{
                cout<<" "<<1;
            }
        }
        cout<<"\n";
        fflush(stdout);

        int res;
        cin>>res;
        reses2[i]=res;
    }
    for (int i=1;i<=n;i++){
        if (reses1[i]==0){
            ans[i]=1;
        }
    }
    int known=1;
    while (known<n){
        for (int j=1;j<=n;j++){
            if (reses1[j]!=0 && ans[j]==-1 && ans[reses1[j]]!=-1){
                ans[j]=ans[reses1[j]]+1;
                known++;
            }
        }
        for (int j=1;j<=n;j++){
            if (reses2[j]!=0 && ans[j]!=-1 && ans[reses2[j]]==-1){
                ans[reses2[j]]=ans[j]+1;
                known++;
            }
        }
    }

    cout<<"!";
    for (int i=1;i<=n;i++){
        cout<<" "<<ans[i];
    }
    cout<<"\n";
    fflush(stdout);
}