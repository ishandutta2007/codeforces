//void __(){
//    _(int,q);
//    priority_queue<pii> pq;
//    queue<int> in;
//    vb visited(q+1);
//    int index = 0;
//    vi ans;
//    rep(t,q){
//        _(int,type);
//        if(type == 1){
//            ++index;
//            _(int,m);
//            pq.push({m,-index});
//            in.push(index);
//            continue;
//        }
//        int x;
//        if(type == 2){
//            while(visited[in.front()])
//                in.pop();
//            x = in.front();
//        }
//        if(type == 3){
//            while(visited[-pq.top().Y])
//                pq.pop();
//            x = -pq.top().Y;
//        }
//        visited[x] = true;
//        ans.pb(x);
//    }
//    print ans;
//}
//
#include <iomanip>
#include <queue>
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
#define Y second
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> pii;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
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
T1 ostream& operator<<(ostream& stream, const vector<T>& t){
    for(int i = 0; i < sz(t); ++i){
        stream << t[i];
        if(i+1 < sz(t))
            stream << ' ';
    }
    return stream;
}
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
void __(){
    _(int,q);
    priority_queue<pii> pq;
    queue<int> in;
    vb visited(q+1);
    int index = 0;
    vi ans;
    rep(t,q){
        _(int,type);
        if(type == 1){
            ++index;
            _(int,m);
            pq.push({m,-index});
            in.push(index);
            continue;
        }
        int x;
        if(type == 2){
            while(visited[in.front()])
                in.pop();
            x = in.front();
        }
        if(type == 3){
            while(visited[-pq.top().Y])
                pq.pop();
            x = -pq.top().Y;
        }
        visited[x] = true;
        ans.pb(x);
    }
    print ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}