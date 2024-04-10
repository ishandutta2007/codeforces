#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second
#define pb push_back

typedef long long ll;      
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int N = 1e6 + 100;

int n, k, a[N], pre[N], t[N], ans, l[N], r[N];
int get(int m, int n){
    return (int)(100.0 * m / n + 0.5);
}
int main(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        t[i] = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        int id = 1;
        for(int j = 1; j <= k; j++)
            if(t[j] < t[id])
                id = j;
        l[i] = t[id];
        r[i] = t[id] + a[i];
        t[id] += a[i];
        pre[t[id]]++;
    }
    for(int i = 1; i < N; i++)
        pre[i] += pre[i - 1];
    for(int i = 1; i <= n; i++){
        bool ok = 0;
        for(int j = l[i]; j < r[i]; j++)
            if(get(pre[j], n) == j - l[i] + 1)
                ok = 1;
        ans += ok;
    }
    cout << ans;
    return 0;
}