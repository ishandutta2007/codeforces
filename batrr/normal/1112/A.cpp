#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second
#define pb push_back

typedef long long ll;      
typedef pair<int, int> pii;
typedef pair<long, long> pll;

const int N = 5000;

int n, m, k, p[N], s[N], mx[N], ans;

int main(){
    cin >> n >> m >> k; 
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        mx[s[i]] = max(mx[s[i]], p[i]);
    }

    for(int i = 1; i <= k; i++){
        int x;
        cin >> x;
        if(mx[s[x]] != p[x])
            ans++;
    }
    cout << ans;
    return 0;
}