#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int num[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int in;
        cin >> in;
        num[in]++;
    }
    int ansval = 0;
    int ansl = -1;
    int ansr = -1;
    int l = 1;
    while(l <= 200001) {
        //cerr << l << endl;
        if(num[l] == 0) {
            l++;
            continue;
        }
        int nowans = num[l];
        int r = l+1;
        while(true) {
            if(num[r] == 0) break;
            if(r-1 != l && num[r-1] == 1) break;
            nowans += num[r];
            r++;
        }
        if(nowans > ansval) {
            ansval = nowans;
            ansl = l;
            ansr = r;
        }
        if(l == r-1) l = r;
        else l = r - 1;
    }
    cout << ansval << endl;
    for(int i = ansl; i < ansr; i++) cout << i << " ";
    for(int val = ansr - 1; val >= ansl; val--) {
        for(int i = 2; i <= num[val]; i++) cout << val << " ";
    }
    cout << endl;
    return 0;
}