#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

const ll mod = 998244353;

struct node {
    node *p[2];
    node(){
        p[0] = p[1] = nullptr;
    }
    ~node(){
        if (p[1] != nullptr) delete p[1];
        if (p[0] != nullptr) delete p[0];
    }
};

node *root = new node();

void u(int x) {
    node *q = root;
    for (int i = 19; i >= 0; i--) {
        int t = 0;
        if ((x & (1 << i))) t = 1;
        if (q -> p[t] == nullptr) q -> p[t] = new node();
        q = q -> p[t];
    }
}

int _min(int x) {
    int res = 0;
    node *q = root;
    for (int i = 19; i >= 0; i--) {
        int t = 0;
        if ((x & (1 << i))) {
            t = 1;
        }
        if (q -> p[t] == nullptr) t ^= 1;
        q = q -> p[t];
        if (t) {
            res += 1 << i;
        }
    }
    return res ^ x;
}

int _max(int x) {
    int res = 0;
    node *q = root;
    for (int i = 19; i >= 0; i--) {
        int t = 1;
        if ((x & (1 << i))) {
            t = 0;
        }
        if (q -> p[t] == nullptr) t ^= 1;
        q = q -> p[t];
        if (t) {
            res += 1 << i;
        }
    }
    return res ^ x;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                                
    #endif     

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        vector <ll> a(r - l + 1);
        delete root;
        root = new node();
        for (auto &i : a) {
            cin >> i;
            u(i);
        }                
        for (auto i : a) {
            if (!(_min(i ^ l) < l || _max(i ^ l) > r)) {
                cout << (i ^ l) << "\n";
                break;
            }        
        }                       
    }
    
    return 0;
}