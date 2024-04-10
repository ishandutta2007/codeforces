#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)

const int maxn = 1e6 + 10;
const int inf = 1e8;
struct asd{
    int cnt, x;
};

int a[maxn][2];
int b[maxn * 2];
asd c[maxn];

bool less1(asd a, asd b){
    return a.cnt > b.cnt;
}

int main(){
   // freopen("in", "r", stdin);
    int n, uk, q, q1, uk1, ans, norm;
    cin >> n;
    uk = 0;
    forn(i, n){
        cin >> a[i][0] >> a[i][1];
        b[uk++] = a[i][0];
        b[uk++] = a[i][1];
    }
    sort(b, b + uk);
    c[0].x = b[0];
    c[0].cnt = 1;
    uk1 = 0;
    forab(i, 1, uk){
        if (b[i - 1] == b[i])
            c[uk1].cnt++;
        else{
            c[++uk1].x = b[i];
            c[uk1].cnt = 1;
        }
    }
    uk1++;
    sort(c, c + uk1, less1);
    ans = inf;
    norm = (n + 1) / 2;
    forn(t, 4){
       // if (c[t].cnt < (n + 1) / 2)
        //    break;
        q = 0;
        q1 = 0;
        forn(i, n){
            if (a[i][0] == c[t].x){
                q++;
                continue;
            }
            if (a[i][1] == c[t].x)
                q1++;
        }
        if (q >= norm){
            ans = 0;
            continue;
        }
        if (q + q1 >= norm)
            ans = min(ans, norm - q);
    }

    if (ans != inf)
        cout << ans;
    else
        cout << -1;
    return 0;
}