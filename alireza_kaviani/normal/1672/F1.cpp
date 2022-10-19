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

int q , n , ans[MAXN] , cnt[MAXN] , A[MAXN];
vector<int> vec[MAXN];
set<pii , greater<pii>> st;

void setVal(int x , int y){
//    cout << x << sep << y << endl;
    ans[vec[x].back()] = y;
    vec[x].pop_back();
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        st.clear();
        for(int i = 1 ; i <= n ; i++){
            vec[i].clear(); cnt[i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
            cnt[A[i]]++;
            vec[A[i]].push_back(i);
        }
        if(n == 1){
            cout << A[1] << endl;
            continue;
        }
        int cur = 0;
        for(int i = 1 ; i <= n ; i++){
            st.insert({cnt[i] , i});
            if(cnt[i] >= cnt[cur]){
                cur = i;
            }
        }
        vector<int> res;
        for(int i = 1 ; i <= n ; i++){
            //cout << cur << endl;
            res.push_back(cur);
            st.erase({cnt[cur] , cur});
            cnt[cur]--;
            st.insert({cnt[cur] , cur});
            auto it = st.begin() , it2 = next(it);
            if((*it).Y != cur || (*it2).X == 0){
                cur = (*it).Y;
            }
            else{
                cur = (*it2).Y;
            }
        }
        for(int i = 0 ; i < n ; i++){
            setVal(res[i] , res[(i + 1) % n]);
        }
        for(int i = 1 ; i <= n ; i++){
            cout << ans[i] << sep;
        }
        cout << endl;
    }

    return 0;
}
/*

*/