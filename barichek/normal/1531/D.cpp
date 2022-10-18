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

char buf[max_n];

string read()
{
    scanf("%s",&buf);
    return buf;
}

string s[max_n];
bitset<max_n> good1;
bitset<max_n> good2;
bitset<max_n> ones;

void set_bits_internal(bitset<max_n>& a,int l,int r,int value)
{
    if (l==r){
        a[l]=value;
    }
    else if (value==1){
        a |= ((ones>>(max_n-1-r))>>l)<<l;
    }
    else if (value==0){
        a ^= a&(ones>>(max_n-1-r))&(ones<<l);
    }
    else{
        assert(0);
    }
}

void set_bits(bitset<max_n>& a,int l,int r,int value)
{
    // cout<<"set_bits :: "<<((uint64_t*)&a==(uint64_t*)&good1 ? "good1" : "good2")<<" "<<l<<" "<<r<<" "<<value<<"\n";
    set_bits_internal(a,max_n-1-r,max_n-1-l,value);
}

int get_last_bit_in_and()
{
    int pos=(good1&good2)._Find_first();
    return max_n-pos-1;
}

void ___main___()
{
    ones.set();

    int n;
    scanf("%d",&n);

    n++;
    s[0]="blue";
    for (int i=1;i<n;i++){
        s[i]=read();
    }

    set<int> locks;
    set<int> unlocks;
    locks.insert(-2);
    unlocks.insert(-1);
    locks.insert(n);
    unlocks.insert(n+1);
    bool locked=0;
    for (int i=0;i<n;i++){
        if (s[i]=="lock"){
            locks.insert(i);
            locked=1;
        }
        else if (s[i]=="unlock"){
            unlocks.insert(i);
            locked=0;
        }
        else{
            set_bits(good2,i,i,1);
        }

        if (!locked){
            set_bits(good1,i,i,1);
        }
    }

    auto get_ans=[&]()
    {
        return s[get_last_bit_in_and()];
    };

    cout<<get_ans()<<"\n";
    int t;
    scanf("%d",&t);
    while (t--){
        int id;
        string t;
        scanf("%d",&id);
        t=read();

        {
            int prev_lock=*(--locks.lower_bound(id));
            int prev_unlock=*(--unlocks.lower_bound(id));
            int next_lock=*(locks.upper_bound(id));
            int next_unlock=*(unlocks.upper_bound(id));
            if (s[id]=="lock"){
                if (prev_lock<prev_unlock){
                    set_bits(good1,id,min(next_lock,next_unlock)-1,1);
                }
                locks.erase(id);
            }
            else if (s[id]=="unlock"){
                if (prev_lock>prev_unlock){
                    set_bits(good1,id,min(next_lock,next_unlock)-1,0);
                }
                unlocks.erase(id);
            }
            else{
                set_bits(good2,id,id,0);
            }
        }
        s[id]=t;
        {
            int prev_lock=*(--locks.lower_bound(id));
            int prev_unlock=*(--unlocks.lower_bound(id));
            int next_lock=*(locks.upper_bound(id));
            int next_unlock=*(unlocks.upper_bound(id));
            if (s[id]=="lock"){
                if (prev_lock<prev_unlock){
                    set_bits(good1,id,min(next_lock,next_unlock)-1,0);
                }
                locks.insert(id);
            }
            else if (s[id]=="unlock"){
                if (prev_lock>prev_unlock){
                    set_bits(good1,id,min(next_lock,next_unlock)-1,1);
                }
                unlocks.insert(id);
            }
            else{
                set_bits(good2,id,id,1);
            }
        }

        cout<<get_ans()<<"\n";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ___main___();

    exit(0);
}