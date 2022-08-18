////!multi
//void __(){
//    _(vi,a,4);
//    sort(all(a));
//    print a[0]*a[2];
//}
//
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
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
#define _IWI(type,name,...) type name(__VA_ARGS__); cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
//!multi
void __(){
    _(vi,a,4);
    sort(all(a));
    print a[0]*a[2];
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