#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1000;
const int inf = 1e9;

struct kart{
    int val, type;
};
kart a[maxn];
int b[maxn];
bool use[maxn];
string s;
int n, m, ans = 0;

void solve(){
    int sum = 0;
    bool flag;
    for(int i = 0; i < n; i++)
        if (a[i].type == 0){
            flag = 1;
            for(int j = 0; flag && j < m; j++)
                if (!use[j] && b[j] > a[i].val){
                    flag = 0;
                    use[j] = 1;
                }
            if (flag) return;

        }
    for(int i = 0; i < n; i++)
        if (a[i].type == 1){
            flag = 1;
            for(int j = 0; flag && j < m; j++)
                if (!use[j] && b[j] >= a[i].val){
                    flag = 0;
                    use[j] = 1;
                    sum += b[j] - a[i].val;
                }
            if (flag) return;
        }
    for(int j = 0; j < m; j++)
        if (!use[j])
            sum += b[j];
    ans = sum;
}

bool cmp(kart A, kart B){
    return A.val < B.val;
}

int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int sum = 0;
    bool flag;
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++){
        cin >> s >> a[i].val;
        if (s[0] == 'A')
            a[i].type = 1;
        else
            a[i].type = 0;
    }
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    sort(b, b + m);
    if (m >= n)
       solve();
    sort(a, a + n, cmp);
    sum = 0;
    memset(use, 0, sizeof(use));
    for(int i = 0; i < n; i++)
        if (a[i].type == 1){
            flag = 1;
            for(int j = m - 1; flag && j >= 0; j--)
                if (!use[j] && b[j] > a[i].val){
                    sum += b[j] - a[i].val;
                    use[j] = 1;
                    flag = 0;
                }

        }
    ans = max(ans, sum);
    cout << ans << endl;
    return 0;
}