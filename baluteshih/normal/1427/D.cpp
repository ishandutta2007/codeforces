#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

pii arr[100005], arr2[100005];
int num[100005], n;
vector<vector<int>> oper;

bool cmp(int a, int b) {
    return arr[a].X < arr[b].X; 
}

void do_oper(vector<int> op) {
    vector<int> tmp;
    for (int i : op)
        if (i)
            tmp.pb(i);
    //cerr << "!!!! ";
    //for (int i = 1; i <= n; ++i)
    //    cerr << arr[i].X << " \n"[i == n];
    if (SZ(tmp) <= 1)
        return;
    op.swap(tmp), oper.pb(op);
    int tp = 0, nw = n;
    for (int i = SZ(op) - 1; i >= 0; --i) {
        for (int j = nw - op[i] + 1; j <= nw; ++j)
            arr2[++tp] = arr[j];
        nw -= op[i];
    }
    for (int i = 1; i <= n; ++i)
        arr[i] = arr2[i];
}

int main() {
    IOS();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i].X, num[i] = i;
    sort(num + 1, num + n + 1);
    for (int i = 1; i <= n; ++i)
        arr[num[i]].Y = i;
    int rbase = (n + 1) / 2 + 1;
    for (int l = 1, r = rbase, i = 0; i < n; ++i) {
        vector<int> op;
        if ((i & 1) ^ (n & 1)) {
            op.pb(r - rbase);
            int cnt = 0;
            for (int j = r - rbase + 1; arr[j].X != l; ++j)
                ++cnt;
            op.pb(cnt);
            op.pb(n - op[0] - op[1] - (l - 1));
            op.pb(l - 1);
            ++l;
        }
        else {
            op.pb(l - 1);
            int cnt = 0;
            for (int j = l; arr[j].X != r; ++j)
                ++cnt;
            op.pb(cnt);
            op.pb(n - op[0] - op[1] - (r - rbase));
            op.pb(r - rbase);
            ++r;
        }
        do_oper(op);
        //cerr << "**** ";
        //for (int j = 1; j <= n; ++j)
        //    cerr << arr[j].X << " \n"[j == n];
    }
    cout << SZ(oper) << "\n";
    for (auto &v : oper) {
        cout << SZ(v);
        for (int i : v)
            cout << " " << i;
        cout << "\n";
    }
}