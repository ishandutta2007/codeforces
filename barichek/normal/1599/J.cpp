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
 
const int max_n = 1e3+10, inf = 1000111222;
const int max_sum=2e6+10;
 
pii any_found[max_sum];
 
int b[max_n];
 
const bool debug=0;
const int debug_A=30;
 
int debug_buf[max_n];
 
bool rec(int pos,const vector<int> &b)
{
    if (pos==len(b)){
        set<int> kek(all(b));
        for (int i=0;i<pos;i++){
            for (int j=i+1;j<pos;j++){
                kek.erase(debug_buf[i]+debug_buf[j]);
            }
        }
        return kek.empty();
    }
    for (int i=-debug_A;i<=debug_A;i++){
        debug_buf[pos]=i;
        if (rec(pos+1,b)){
            return 1;
        }
    }
    return 0;
}
 
bool naive(vector<int> b)
{
    return rec(0,b);
}
 
bool ok_my_ans(vector<int> my_ans,vector<int> b)
{
    if (len(my_ans)!=len(b)){
        return 0;
    }
    set<int> kek(all(b));
    for (int i=0;i<len(my_ans);i++){
        for (int j=i+1;j<len(my_ans);j++){
            kek.erase(my_ans[i]+my_ans[j]);
        }
    }
    return kek.empty();
}
 
void my_assert(bool a)
{
    if (!a){
        cout<<"VERY BAD"<<"\n";
        exit(0);
    }
}
 
bool get_bit(int mask,int bit)
{
    return (mask>>bit)&1;
}
 
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
 
    double start = clock();
 
    srand(29982);
 
    start_of_program:;
 
    static int test_id=0;
 
    if (debug){
        cout<<test_id++<<" +++ "<<"\n";
    }
 
    int n;
    if (debug){
        n=5;//+rand()%2;
        for (int i=0;i<250;i++){
            any_found[i]=mp(0,0);
        }
        cout<<n<<"\n";
    }
    else{
        cin>>n;
    }
    bool any=0;
    vector<int> odds;
    for (int i=1;i<30;i+=2){
        odds.pb(i);
    }
    random_shuffle(all(odds));
    for (int i=0;i<n;i++){
        if (debug){
            if (1 || test_id%2==0){
                b[i]=odds.back();
                odds.pop_back();
            }
            else{
                b[i]=rand()%15;
            }
            cout<<b[i]<<" ";
        }
        else{
            cin>>b[i];
        }
        any|=(b[i]%2==0);
    }
    if (debug){
        cout<<"\n";
    }
    sort(b,b+n);
 
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (b[i]==b[j]){
                cout<<"YES"<<"\n";
                cout<<0<<" "<<b[i]<<" ";
                for (int k=0;k<n;k++){
                    if (k!=i && k!=j){
                        cout<<b[k]<<" ";
                    }
                }
                cout<<"\n";
 
                if (debug){
                    vector<int> my_ans;
                    my_ans.pb(0);
                    my_ans.pb(b[i]);
                    for (int k=0;k<n;k++){
                        if (k!=i && k!=j){
                            my_ans.pb(b[k]);
                        }
                    }
                    my_assert(ok_my_ans(my_ans,{b,b+n}));
                    my_assert(naive({b,b+n}));
                    goto start_of_program;
                }
                else{
                    return 0;
                }
            }
        }
    }
 
    if (n==2){
        cout<<"NO"<<"\n";
 
        if (debug){
            my_assert(!naive({b,b+n}));
            goto start_of_program;
        }
        else{
            return 0;
        }
    }
 
    if (n==3){
        int sum=b[0]+b[1]+b[2];
        if (sum%2==0){
            cout<<"YES"<<"\n";
            cout<<sum/2-b[0]<<" "<<sum/2-b[1]<<" "<<sum/2-b[2]<<"\n";
 
            if (debug){
                vector<int> my_ans;
                my_ans.pb(sum/2-b[0]);
                my_ans.pb(sum/2-b[1]);
                my_ans.pb(sum/2-b[2]);
                my_assert(ok_my_ans(my_ans,{b,b+n}));
                my_assert(naive({b,b+n}));
                goto start_of_program;
            }
            else{
                return 0;
            }
        }
        else{
            cout<<"NO"<<"\n";
 
            if (debug){
                my_assert(!naive({b,b+n}));
                goto start_of_program;
            }
            else{
                return 0;
            }
        }
    }
 
    if (any){
        vector<int> poses_even;
        vector<int> poses_odd;
        for (int i=0;i<n;i++){
            if (b[i]%2==0){
                poses_even.pb(i);
            }
            else{
                poses_odd.pb(i);
            }
        }
 
        my_assert(!poses_even.empty());
 
        int p1=-1;
        int p2=-1;
        int p3=-1;
 
        if (len(poses_odd)>=2){
            p1=poses_even[0];
            p2=poses_odd[0];
            p3=poses_odd[1];
        }
        else{
            my_assert(len(poses_even)>=3);
            p1=poses_even[0];
            p2=poses_even[1];
            p3=poses_even[2];
        }
 
        int sum=b[p1]+b[p2]+b[p3];
        my_assert(sum%2==0);
 
        cout<<"YES"<<"\n";
        cout<<sum/2-b[p1]<<" "<<sum/2-b[p2]<<" "<<sum/2-b[p3]<<" ";
        for (int i=0;i<n;i++){
            if (i!=p1 && i!=p2 && i!=p3){
                cout<<b[i]-(sum/2-b[p1])<<" ";
            }
        }
        cout<<"\n";
 
        if (debug){
            vector<int> my_ans;
            my_ans.pb(sum/2-b[p1]);
            my_ans.pb(sum/2-b[p2]);
            my_ans.pb(sum/2-b[p3]);
            for (int i=0;i<n;i++){
                if (i!=p1 && i!=p2 && i!=p3){
                    my_ans.pb(b[i]-(sum/2-b[p1]));
                }
            }
            my_assert(ok_my_ans(my_ans,{b,b+n}));
            my_assert(naive({b,b+n}));
            goto start_of_program;
        }
        else{
            return 0;
        }
    }
 
    if (debug){
        cout<<"here"<<"\n";
    }
 
    // all are odd
 
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (any_found[b[i]+b[j]]!=mp(0,0)){
                int p1=any_found[b[i]+b[j]].fir;
                int p2=i;
                int p3=j;
                int p4=any_found[b[i]+b[j]].sec;
 
                my_assert(p1!=p2);
                my_assert(p1!=p3);
                my_assert(p1!=p4);
                my_assert(p2!=p3);
                my_assert(p2!=p4);
                my_assert(p3!=p4);
 
                cout<<"YES"<<"\n";
                cout<<0<<" "<<b[p3]-b[p1]<<" "<<b[p1]<<" "<<b[p2]<<" ";
                for (int i=0;i<n;i++){
                    if (i!=p1 && i!=p2 && i!=p3 && i!=p4){
                        cout<<b[i]<<" ";
                    }
                }
                cout<<"\n";
 
                if (debug){
                    vector<int> my_ans;
                    my_ans.pb(0);
                    my_ans.pb(b[p3]-b[p1]);
                    my_ans.pb(b[p1]);
                    my_ans.pb(b[p2]);
                    for (int i=0;i<n;i++){
                        if (i!=p1 && i!=p2 && i!=p3 && i!=p4){
                            my_ans.pb(b[i]);
                        }
                    }
                    my_assert(ok_my_ans(my_ans,{b,b+n}));
                    my_assert(naive({b,b+n}));
                    goto start_of_program;
                }
                else{
                    return 0;
                }
            }
            any_found[b[i]+b[j]]=mp(i,j);
        }
    }
 
    const int nn=min(n,30);
 
    vector<int> p;
    for (int i=0;i<nn;i++){
        p.pb(i);
    }
    map<pii,int> mapa;
 
    vector<int> ids1;
    vector<int> ids2;
 
    while ((clock()-start)/CLOCKS_PER_SEC<0.15){
        random_shuffle(all(p));
        int mask=0;
        int cnt=0;
        int sum=0;
        bool flag=0;
        for (auto i:p){
            mask|=(1ll<<i);
            cnt++;
            sum+=b[i];
            auto it = mapa.find(mp(cnt,sum));
            if (it != mapa.end() && it->second != mask) {
                int mask1=mask;
                int mask2=it->second;
 
                for (int i=0;i<nn;i++){
                    if (get_bit(mask1,i) && !get_bit(mask2,i)){
                        ids1.pb(i);
                    }
                }
                for (int i=0;i<nn;i++){
                    if (!get_bit(mask1,i) && get_bit(mask2,i)){
                        ids2.pb(i);
                    }
                }
                flag=1;
                break;
            }
            mapa[mp(cnt,sum)]=mask;
        }
        if (flag){
            break;
        }
    }
 
    if (len(ids1)>0)
    {
//        for (int i=0;i<len(ids1);i++){
//            cout<<ids1[i]<<" ";
//        }
//        cout<<"\n";
//        for (int i=0;i<len(ids2);i++){
//            cout<<ids2[i]<<" ";
//        }
//        cout<<"\n";
        vector<int> ans;
        ans.pb(0);
        for (int i=0;i<len(ids1);i++){
            int id1=ids1[i];
            int id2=ids2[i];
            if (i%2==0){
                swap(id1,id2);
            }
 
            ans.pb(b[id1]-ans.back());
            if (i!=len(ids1)-1){
                ans.insert(ans.begin(),b[id2]-ans.front());
            }
        }
 
        vector<bool> have(n,0);
        for (auto i:ids1){
            have[i]=1;
        }
        for (auto i:ids2){
            have[i]=1;
        }
        for (int i=0;i<n;i++){
            if (!have[i]){
                ans.pb(b[i]);
            }
        }
 
        cout<<"YES"<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
 
//        my_assert(ok_my_ans(ans,{b,b+n}));
 
        return 0;
    }
 
    cout<<"NO"<<"\n";
 
    if (debug){
        my_assert(!naive({b,b+n}));
        goto start_of_program;
    }
    else{
        return 0;
    }
}