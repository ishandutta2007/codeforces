
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
 
const int max_n = 1e6+10, inf = 1000111222;
 
int __gcd(int a,int b)
{
    while (a&&b){
        if (a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return a+b;
}
 
int a[max_n];
 
vector<int> prime_div[max_n];


 
vector<int> reb1[2*max_n];
int comp1[2*max_n];
 
void dfs1(int now,int comp)
{
    comp1[now]=comp;
    for (auto wh:reb1[now]){
        if (!comp1[wh]){
            dfs1(wh,comp);
        }
    }
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    for (int i=2;i<max_n;i++){
        if (prime_div[i].empty()){
            for (int j=i;j<max_n;j+=i){
                prime_div[j].pb(i);
            }
        }
    }
 
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
 
//        cout<<"a[i] :: "<<a[i]<<" :: ";
//        for (auto j:prime_div[a[i]]){
//            cout<<j<<" ";
//        }
//        cout<<"\n";
 
        for (int j1=0;j1<len(prime_div[a[i]]);j1++){
            reb1[i].pb(n+prime_div[a[i]][j1]);
            reb1[n+prime_div[a[i]][j1]].pb(i);
        }
    }
 
    int comp=1;
    for (int i=0;i<n+max_n;i++){
        if (!comp1[i]){
            dfs1(i,comp++);
        }
    }
 
    vector<pii> goods;
 
    for (int i=0;i<n;i++){
        vector<int> cur=prime_div[a[i]];
        for (auto j:prime_div[a[i]+1]){
            cur.pb(j);
        }
        for (int i=0;i<len(cur);i++){
            for (int j=i+1;j<len(cur);j++){
                int a=comp1[n+cur[i]];
                int b=comp1[n+cur[j]];
                if (a>b){
                    swap(a,b);
                }
//                cout<<"a b :: "<<a<<" "<<b<<"\n";
                goods.pb(mp(a,b));
            }
        }
    }
 
    sort(all(goods));
    goods.erase(unique(all(goods)),goods.end());
 
//    cout<<comp1[n+2]<<" "<<comp1[n+3]<<" "<<comp1[n+5]<<"\n";
 
    for (int i=0;i<q;i++){
        int s,t;
        scanf("%d%d",&s,&t);
        s--;
        t--;
 
        int A=comp1[s];
        int B=comp1[t];
        if (A>B){
            swap(A,B);
        }
 
        if (comp1[s]==comp1[t]){
            cout<<0<<"\n";
        }
        else if (/*__gcd(a[s]+1,a[t])!=1 || __gcd(a[s],a[t]+1)!=1 || */binary_search(all(goods),mp(A,B))) {
            cout<<1<<"\n";
        }
        else{
            cout<<2<<"\n";
        }
    }
}