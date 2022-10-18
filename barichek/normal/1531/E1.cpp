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

const int max_n = 100, inf = 1000111222;

vector<int> dp1[max_n];
pair<vector<int>,vector<int>> dp2[max_n];

void get_rec(vector<int> a,string& res)
{
    if (len(a)==1){
        return;
    }
//    cout<<"get_rec :: ";
//    for (auto i:a){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
    assert(len(a)%2==0);
    vector<int> a1(a.begin(),a.begin()+len(a)/2);
    vector<int> a2(a.begin()+len(a)/2,a.end());
    get_rec(a1,res);
    get_rec(a2,res);
    sort(all(a1));
    sort(all(a2));
    int p1=0,p2=0;
    while (p1<len(a1) && p2<len(a2)){
        if (a1[p1]<a2[p2]){
            res.pb('0');
            p1++;
        }
        else{
            res.pb('1');
            p2++;
        }
    }
}

string get(vector<int> a)
{
    string res;
    get_rec(a,res);
    return res;
}

void ___main___()
{
    string s;
    cin>>s;

    {
        vector<int> p;
        for (int i=0;i<8;i++){
            p.pb(i);
        }
        do{
            auto g=get(p);
            if (len(g)<=len(s) && s.substr(0,len(g))==g){
                dp1[len(g)]=p;
            }
        }
        while (next_permutation(all(p)));
    }
    {
        vector<int> p;
        for (int i=0;i<8;i++){
            p.pb(i);
        }
        do{
            auto g=get(p);
            for (int from=0;from<max_n;from++){
                if (!dp1[from].empty() && from+len(g)<=len(s) && s.substr(from,len(g))==g){
                    dp2[from+len(g)]=mp(dp1[from],p);
                }
            }
        }
        while (next_permutation(all(p)));
    }

    for (int i=0;i<=len(s);i++){
        if (!dp2[i].fir.empty()){
            int cnt0=0;
            int cnt1=0;
            for (int j=i;j<len(s);j++){
                if (s[j]=='0'){
                    cnt0++;
                }
                else{
                    cnt1++;
                }
            }
            if ((cnt0==8 || cnt1==8) && cnt0<=8 && cnt1<=8){
                vector<int> for1;
                vector<int> for2;
                int cur=0;
                for (int j=i;j<len(s);j++){
                    if (s[j]=='0'){
                        for1.pb(cur++);
                    }
                    else{
                        for2.pb(cur++);
                    }
                }
                while (for1.size()<8){
                    for1.pb(cur++);
                }
                while (for2.size()<8){
                    for2.pb(cur++);
                }

                vector<int> ans;
                for (auto i:dp2[i].fir){
                    ans.pb(for1[i]);
                }
                for (auto i:dp2[i].sec){
                    ans.pb(for2[i]);
                }
                assert(len(ans)==16);
                assert(get(ans)==s);
                cout<<len(ans)<<"\n";
                for (auto i:ans){
                    cout<<i+1<<" ";
                }
                cout<<"\n";
            }
        }
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}