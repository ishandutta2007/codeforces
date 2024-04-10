////!multi
//bool solve(vi gaps, int k){
//    if(sz(gaps) == 1)
//        return false;
//    int s = sum(gaps);
//    if(s%(2*k))
//        return false;
//    for(int x : gaps)
//        if(x >= s-(k-1))
//            return false;
//    if(s != 2*k)
//        return true;
//    int t = 0;
//    for(int x : gaps){
//        t += x;
//        if(t == k)
//            return true;
//    }
//    return false;
//}
//void test(){
//    vi gaps = {1,7};
//    int k = 2;
//    print solve(gaps,k);
//}
//void __(){
//    _(int,n);
//    _(int,k);
//    _(int,m);
//    _(vi,arr,m);
//    arr.insert(arr.begin(),0);
//    arr.pb(n+1);
//    vi gaps;
//    rep(i,sz(arr)-1){
//        int g = arr[i+1]-arr[i]-1;
//        if(g)
//            gaps.pb(g);
//    }
//    if(solve(gaps,k/2))
//        print "YES";
//    else
//        print "NO";
//
//}
//
#include <iomanip>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define pb push_back
#define REP_ZERO_INT(i,r) for(int i = 0; i < (r); ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<int> vi;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
T1 istream& operator>>(istream& stream, vector<T>& t){
    return read(all(t), stream);
}
T1 istream& read(T b, T e, istream& stream){
    for(T it = b; it != e; ++it)
        stream >> *it;
    return stream;
}
T1 T sum(vector<T>& arr){
    T ans = 0;
    for(auto x : arr)
        ans += x;
    return ans;
}
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout) 
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }

    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};
#define print _print(),
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define _IWI(type,name,...) type name(__VA_ARGS__); cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
//!multi
bool solve(vi gaps, int k){
    if(sz(gaps) == 1)
        return false;
    int s = sum(gaps);
    if(s%(2*k))
        return false;
    for(int x : gaps)
        if(x >= s-(k-1))
            return false;
    if(s != 2*k)
        return true;
    int t = 0;
    for(int x : gaps){
        t += x;
        if(t == k)
            return true;
    }
    return false;
}
void test(){
    vi gaps = {1,7};
    int k = 2;
    print solve(gaps,k);
}
void __(){
    _(int,n);
    _(int,k);
    _(int,m);
    _(vi,arr,m);
    arr.insert(arr.begin(),0);
    arr.pb(n+1);
    vi gaps;
    rep(i,sz(arr)-1){
        int g = arr[i+1]-arr[i]-1;
        if(g)
            gaps.pb(g);
    }
    if(solve(gaps,k/2))
        print "YES";
    else
        print "NO";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        __();
    }
}