#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x,v) for(auto &x : v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define rrep(i,a,b) for(int i = b; i --> a;)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const int N = (1<<20);
struct Tree {
    ll sum[2*N] = {}, last[2*N];
    void touch(int v) {
        sum[v] = sum[2*v]+sum[2*v+1];
        last[v] = max(last[2*v]+sum[2*v+1], last[2*v+1]);
    }
    Tree() {
        for(int i=0; i<N; ++i) last[i+N] = i;
        for(int i=N-1; i>=1; --i) touch(i);
    }
    void update(int v, ll d) {
        v += N;
        last[v] = v-N+d;
        sum[v] = d;
        while(v/2!=0) {
            v /= 2;
            touch(v);
        }
    }
    ll query(int t) {
        t += N;
        ll res = last[t], s = sum[t];
        while(t != 1) {
            if(t%2==1) {
                res = max(res, last[t-1]+s);
                s += sum[t-1];
            }
            t /= 2;
        }
        return res;
    }
};

Tree tr;
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<int> hist;
	while(n--) {
        char q;
        cin >> q;
        if(q=='?') {
            int t;
            cin >> t;
            hist.push_back(0);
            cout << tr.query(t)-t << "\n";
        }
        else if(q=='+') {
            int t, d;
            cin >> t >> d;
            hist.push_back(t);
            tr.update(t, d);
        }
        else if(q=='-') {
            int num;
            cin >> num;
            --num;
            hist.push_back(0);
            tr.update(hist[num], 0);
        }
	}
}