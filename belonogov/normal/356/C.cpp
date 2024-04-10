#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = -1;
const int inf = 1e9;
const int maxcnt = 13;
const int magic = 6;
const int magic2 = 8;

int dp[maxcnt * maxcnt * maxcnt * maxcnt];
queue < int > q;
int a[5];
int b[5];

void decode(int mask){
    for (int i = 1; i <= 4; i++){
        a[i] = mask % maxcnt;
        mask /= maxcnt;     
    }   
}

int code(int * a){
    int ans = 0;
    for (int i = 4; i >= 1; i--)
        ans = ans * maxcnt + a[i];
    return ans; 
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int mask, new_mask, d, n, x, ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < maxcnt; i++)
        for (int j = 0; j < maxcnt; j++){
            mask = i * maxcnt * maxcnt * maxcnt + j * maxcnt * maxcnt;
            dp[mask] = 0;
            q.push(mask);
        }
//  int i = 0;
    while (!q.empty()){
//      cerr << i++ << endl;
        mask = q.front();
        q.pop();
        decode(mask);
        for (int i = 1; i <= 4; i++)
            for (int j = 0; j <= 3; j++){
                if (a[i]){
                    a[i]--;
                    a[i - 1]++;
                    a[j + 1]++;
                    a[j]--;
                    
                    if (a[j + 1] < maxcnt && (a[i - 1] < maxcnt || i - 1 == 0)){
                        new_mask = code(a);
//                      cerr << new_mask << endl;
                        if (dp[new_mask] == -1){
                            dp[new_mask] = dp[mask] + 1;
                            q.push(new_mask);                       
                        }
                    }
                    a[i]++;
                    a[i - 1]--;
                    a[j + 1]--;
                    a[j]++;     
                }
            }
    }
    //cerr << "read\n";
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        b[x]++; 
    }
    ans = 0;
    d = min(b[1], b[2]);
    ans += d;
    b[1] -= d;
    b[2] -= d;
    b[3] += d;
    for (; b[1] > magic; b[1] -= 3, b[3] += 1, ans += 2);
    for (; b[2] > magic; b[2] -= 3, b[3] += 2, ans += 2);
    b[3] = min(b[3], magic2);
    b[4] = min(b[4], magic2);
    mask = code(b);
    if (dp[mask] == -1){
        cout << -1 << endl;
        return 0;       
    }
    cout << ans + dp[mask] << endl;
    
 
 
    return 0;
}