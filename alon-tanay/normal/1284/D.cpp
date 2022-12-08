#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ld long double
#define f first
#define s second

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pi> A(n);
    vector<pi> B(n);
    for(int i = 0; i < n; i ++) {
        cin >> A[i].f >> A[i].s;
        cin >> B[i].f >> B[i].s;
    }
    bool found = false;
    pbds beP;
    pbds enP;
    vector<pi> ends(n);
    for(int i = 0; i < n; i ++) {
        ends[i] = {A[i].s,i};
    }
    vector<pi> begs(n);
    for(int i = 0; i < n; i ++) {
        begs[i] = {A[i].f,i};
    }
    sort(ends.begin(), ends.end());
    sort(begs.begin(), begs.end());
    int idx = n;
    for(int i = n - 1 ; i >= 0; i --) {
        pi cur = ends[i];
        while(idx > 0 && begs[idx-1].f > cur.f) {
            idx --;
            int j = begs[idx].s;
            beP.insert(B[j].f);
            enP.insert(B[j].s);
        }
        int j = cur.s;
        int ordBE = beP.order_of_key(B[j].s+1);
        int ordEB = enP.order_of_key(B[j].f);
        if(ordEB + (beP.size() - ordBE) != beP.size()) {
            // cout << i << "! (A)" << endl;
            found = true;
        }
        
    }
    beP.clear();
    enP.clear();
    for(int i = 0; i < n; i ++) {
        ends[i] = {B[i].s,i};
    }
    for(int i = 0; i < n; i ++) {
        begs[i] = {B[i].f,i};
    }
    sort(ends.begin(), ends.end());
    sort(begs.begin(), begs.end());
    idx = n;
    for(int i = n -1 ; i >= 0; i --) {
        pi cur = ends[i];
        while(idx > 0 && begs[idx-1].f > cur.f) {
            idx --;
            int j = begs[idx].s;
            beP.insert(A[j].f);
            enP.insert(A[j].s);
        }
        int j = cur.s;
        int ordBE = beP.order_of_key(A[j].s+1);
        int ordEB = enP.order_of_key(A[j].f);
        if(ordEB + (beP.size() - ordBE) != beP.size()) {
            // cout << i << "! (B)" << endl;
            found = true;
        }
        
    }
    cout << (found ? "NO" : "YES");
    return 0;
}

/*

3
1 3 2 4
4 5 6 7
3 4 5 5

3
2 4 1 3
6 7 4 5
5 5 3 4
*/