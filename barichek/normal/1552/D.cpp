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

void rec(bool& res,const vector<int>& a,int pos,int sum1,int sum2,bool taken=0)
{
    if (pos==len(a)){
        if (taken && sum1==sum2){
            res=1;
        }
        return;
    }
    rec(res,a,pos+1,sum1,sum2,taken);
    rec(res,a,pos+1,sum1+a[pos],sum2,1);
    rec(res,a,pos+1,sum1,sum2+a[pos],1);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int test;
    cin>>test;
    while (test--){
        int n;
        cin>>n;
        vector<int> a(n);
        bool res=0;
        for (auto& i:a){
            cin>>i;
            i=abs(i);
            if (i==0){
                res=1;
            }
        }

        sort(all(a));
        rec(res,a,0,0,0,0);

        if (res){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}