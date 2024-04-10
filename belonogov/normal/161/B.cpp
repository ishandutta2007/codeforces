#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 1e9 + 1;
struct p{
    int x, i;
};

p a[10000];
p b[10000];
int ans[1000][1000];
int uk[1000];

bool f(p a, p b){
    return a.x > b.x;
}

int main(){
     long double cnt = 0;
    int n, i, j, uk1 = 0, uk2 = 0, x, q, k;
    bool check;
    cin >> n >> k;
    for (i = 0; i < n; i++){
        cin >> x >> q;
        if (q == 1){
            a[uk1].i = i;
            a[uk1++].x = x;
        }
        if (q == 2){
            b[uk2].i = i;
            b[uk2++].x = x;
        }
    }
    sort(a, a + uk1, f);
    check = false;
    if (uk1 >= k)
        check = true;
    q = inf;
    for (i = 0; i < n; i++){
        if (i < k - 1){
            if (i < uk1){
                ans[i][0] = a[i].i;
                uk[i] = 1;
                cnt += a[i].x / 2.0;
            }
            else{
                ans[i][0] = b[i - uk1].i;
                uk[i] = 1;
                cnt += b[i - uk1].x;
            }
        }
        else{
            if (i < uk1){
                ans[k - 1][uk[k - 1]++] = a[i].i;
                cnt += a[i].x;
                q = min(q, a[i].x); 
            }
            else{
                ans[k - 1][uk[k - 1]++] = b[i - uk1].i;
                cnt += b[i - uk1].x;
                q = min(q, b[i - uk1].x);       
            }
        }
    }
    if (check)
        cnt -= q / 2.0;
    cout.precision(1);
    cout << fixed << cnt << endl;
    for (i = 0; i < k; i++){
        cout << uk[i] << " ";
        for (j = 0; j < uk[i]; j++)
            cout << ans[i][j] + 1 << " ";
        cout << endl;
    }

    return 0;
}