#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int cnt1[N];
int cnt2[N];


int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    int n, k, g;
    scanf("%d%d%d", &n, &k, &g);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt1[x]++;
    }

    for (int i = 0; i < k; i++) {
        memset(cnt2, 0, sizeof(cnt2)); 
        int t = 1;
        for (int j = 0; j < pw(10); j++) {      
            int h = (cnt1[j] + t);
            int mv = h / 2;
            //if (mv != 0)
                //db2(j, mv);
            cnt2[j ^ g] += mv;
            cnt2[j] += cnt1[j] - mv;
            t = h % 2;
        }
        memcpy(cnt1, cnt2, sizeof(cnt2));
    }
    //for (int i = 0; i < 20; i++) {
        //db2(i, cnt1[i]);
    //}
    int mn = INF;
    int mx = 0;
    for (int j = 0; j < pw(10); j++)
        if (cnt1[j] > 0) {
            mn = min(mn, j);
            mx = max(mx, j);
        }
    cout << mx << " " << mn << endl;
        
    return 0;
}