#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int n = str.length();
    vector<int> preA(n+1);
    vector<int> preB(n+1);
    int idx = 0;
    int sumA = 0;
    int sumB = 0;
    for(int i = 0; i < n; i ++) {
        if(str[i] == 'a') {sumA++;}
        else {sumB++;}
        preA[i+1] = sumA;
        preB[i+1] = sumB;
    }
    int mn = sumB;
    for(int i = 0; i < n; i ++) {
        if(str[i] == 'a') { continue; }
        for(int j = i; j < n; j ++) {
            if(str[i] == 'a') { continue; }
            mn = min(mn,preB[i]+sumB-preB[j+1]+preA[j+1]-preA[i]);
        }
    }
    cout << n-mn;
    return 0;
}