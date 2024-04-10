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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , m , A[MAXN] , B[MAXN] , L[MAXN] , R[MAXN] , ps[MAXN] , mark[MAXN];
vector<int> vec[MAXN];
queue<int> Q;
set<ll> st;

void Erase(int x){
    st.erase(x); ps[x] = 0;
    for(int i : vec[x]){
        if(mark[i]) continue;
        if(ps[L[i]] == 0 && ps[R[i]] == 0){
            mark[i] = 1;
            Q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> m;
        st.clear();
        fill(mark , mark + m + 5 , 0);
        fill(vec , vec + n + 5 , vector<int>());
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
        }
        for(int i = 1 ; i <= n ; i++){
            cin >> B[i];
            A[i] -= B[i];
            ps[i] = ps[i - 1] + A[i];
            if(ps[i] != 0){
                st.insert(i);
            }
        }
        for(int i = 0 ; i < m ; i++){
            cin >> L[i] >> R[i]; L[i]--;
            vec[L[i]].push_back(i);
            vec[R[i]].push_back(i);
            if(ps[L[i]] == 0 && ps[R[i]] == 0){
                mark[i] = 1;
                Q.push(i);
            }
        }
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            int l = L[v] , r = R[v];
            while(SZ(st)){
                auto it = st.upper_bound(l);
                if(it == st.end())  break;
                if((*it) > r)   break;
                Erase((*it));
            }
        }
        if(SZ(st) > 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }

    return 0;
}
/*

*/