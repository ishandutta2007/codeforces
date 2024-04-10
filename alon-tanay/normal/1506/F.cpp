#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pi> ps(n);
        for(pi &p : ps) {
            cin >> p.f;
        }
        for(pi &p : ps) {
            cin >> p.s;
        }
        sort(ps.begin(),ps.end());
        int cost = 0;
        pi lst = {1,1};
        for(int i = 0; i < n; i ++) {
            pi cur = ps[i];
            if((lst.f + lst.s)&1) {
                cost += ((cur.f-lst.f)-(cur.s - lst.s)+1)/2;
            } else {
                if(cur.f-lst.f == cur.s-lst.s) {
                    cost += cur.f-lst.f;
                } else {
                    lst.f ++;
                    cost += ((cur.f-lst.f)-(cur.s - lst.s)+1)/2;
                }
            }
            lst = cur;
        }
        cout << cost << "\n";
    }
    return 0;
}