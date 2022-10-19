#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e5 + 10;
const ll MAXK = 1e7 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , pr[MAXK] , u[MAXK] , A[MAXN] , L[MAXN] , R[MAXN] , mid[MAXN] , cnt[MAXK] , mark[MAXN] , ptr[MAXN] , cntPrime[MAXK];
vector<int> dv[MAXN] , Q[MAXN] , adj[MAXN] , comp[MAXN] , vec , ans;
vector<pii> comps;

vector<int> getPrimes(int x){
    vector<int> res;
    while(x > 1){
        int dv = pr[x];
        while(x % dv == 0){
            x /= dv;
        }
        res.push_back(dv);
        cntPrime[dv]++;
    }
    return res;
}

vector<int> getDivisors(int x){
    vector<int> pr = getPrimes(x) , res;
    int k = SZ(pr);
    for(int i = 0 ; i < (1 << k) ; i++){
        int val = 1;
        for(int j = 0 ; j < k ; j++){
            if(i & (1 << j)){
                val *= pr[j];
            }
        }
        u[val] = (__builtin_popcount(i) % 2 == 0 ? 0 : 1);
        res.push_back(val);
    }
    return res;
}

void add(int x){
    for(int i : dv[x]){
        cnt[i]++;
    }
}

int get(int x){
    int res = 0;
    for(int i : dv[x]){
        if(u[i]){
            res -= cnt[i];
        }
        else{
            res += cnt[i];
        }
    }
    return res;
}

void DFS(int v , int root){
    mark[v] = 1;
    comp[root].push_back(v);
    for(int u : adj[v]){
        if(!mark[u]){
            DFS(u , root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 2 ; i < MAXK ; i++){
        if(pr[i])   continue;
        for(int j = i ; j < MAXK ; j += i){
            pr[j] = i;
        }
    }

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
        dv[i] = getDivisors(A[i]);
        L[i] = -1; R[i] = n;
    }

    for(int i = 0 ; i < MAXK ; i++){
        if(cntPrime[i] >= k){
            int cnt = 0;
            for(int j = 0 ; j < n && cnt < k ; j++){
                if(A[j] % i == 0){
                    cout << j + 1 << sep;
                    cnt++;
                }
            }
            return 0;
        }
    }

    for(int i = 0 ; i < 17 ; i++){
        memset(cnt , 0 , sizeof(cnt));
        for(int j = 0 ; j < MAXN ; j++){
            Q[j].clear();
        }
        for(int j = 0 ; j < n ; j++){
            mid[j] = (L[j] + R[j] >> 1);
            Q[mid[j]].push_back(j);
        }
        for(int j = 0 ; j < n ; j++){
            add(j);
            for(int k : Q[j]){
                if(get(k) > 0)  R[k] = mid[k];
                else    L[k] = mid[k];
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(R[i] == n)   continue;
        adj[i].push_back(R[i]);
        adj[R[i]].push_back(i);
    }

    for(int i = 0 ; i < n ; i++){
        if(get(i) > 1){
            for(int j = 0 ; j < n ; j++){
                if(__gcd(A[i] , A[j]) == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(!mark[i]){
            DFS(i , i);
            if(SZ(comp[i]) == 1){
                vec.push_back(i);
            }
            else{
                comps.push_back({SZ(comp[i]) , i});
            }
        }
    }

    if(SZ(vec) >= k){
        for(int i = 0 ; i < k ; i++){
            cout << vec[i] + 1 << sep;
        }
        return 0;
    }

    sort(all(comps) , greater<pii>());
    
    if(comps[0].X == 2){
        int cnt = 0;
        for(int i = 0 ; cnt < k && i < SZ(comps) ; i++ , cnt++){
            cout << comps[i].Y + 1 << sep;
        }
        for(int i = 0 ; cnt < k ; i++ , cnt++){
            cout << vec[i] + 1 << sep;
        }
        cout << endl;
        return 0;
    }

    for(int i = 0 ; i < SZ(comps) ; i++){
        if(SZ(ans) + 2 > k) continue;
        int v = comps[i].Y;
        for( ; ptr[i] < 2 ; ptr[i]++){
            ans.push_back(comp[v][ptr[i]]);
        }
    }
    for(int i = 0 ; i < SZ(comps) ; i++){
        int v = comps[i].Y;
        for( ; ptr[i] < SZ(comp[v]) && SZ(ans) < k ; ptr[i]++){
            ans.push_back(comp[v][ptr[i]]);
        }
    }

    for(int i : ans){
        cout << i + 1 << sep;
    }

    return 0;
}
/*

*/