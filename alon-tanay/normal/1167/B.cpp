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

vector<int> nums = {4,8,16,15,23,42};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> res(6);
    cout << "? 1 2" << endl;
    int ans, a;
    cin >> ans;
    if(ans%42 == 0) {
        a = 42;
    } else if(ans%15 == 0) {
        a = 15;
    } else if(ans%23 == 0) {
        a = 23;
    } else {
        int b;
        if(ans == 32) {
            a = 8;
            b = 4;
        } else if(ans == 64) {
            a = 16;
            b = 4;
        } else {
            a = 16;
            b = 8;
        }
        cout << "? 1 3" << endl;
        cin >> ans;
        if((ans%7 != 0) && (ans%5 != 0) && (ans%23 != 0)) {
            int c;
            if(a == 4 || b == 4) {
                if(a == 8 || b == 8) {
                    c = 16;
                } else {
                    c = 8;
                }
            } else {
                c = 4;
            }
            if(a*c == ans) {
                res[1] = b;
                res[0] = a;
                res[2] = c;
            } else {
                res[1] = a;
                res[0] = b;
                res[2] = c;
            }
        } else {
            if(ans%a != 0) {
                res[0] = b;
                res[1] = a;
                res[2] = ans / b;
            } else {
                res[1] = b;
                res[0] = a;
                res[2] = ans / a;
            }
        }
        cout << "? 4 4" << endl;
        cin >> ans;
        res[3] = sqrt(ans);
        
        cout << "? 5 5" << endl;
        cin >> ans;
        res[4] = sqrt(ans);

        for(int num : nums) {
            bool found = false;
            for(int i = 0; i < 5; i ++) {
                if(res[i] == num) { found = true; break; }
            }
            if(!found) {
                res[5] = num;
                break;
            }
        }
        cout << "! ";
        for(int i = 0; i < 6; i ++) {
            cout << res[i] << " ";
        }
        cout << endl;
        return 0;
    }
    int b = ans / a;    
    cout << "? 1 3" << endl;
    cin >> ans;
    if(ans%a == 0) {
        res[0] = a;
        res[1] = b;
        res[2] = ans / a;
    } else {
        res[1] = a;
        res[0] = b;
        res[2] = ans / b;
    }
    cout << "? 4 4" << endl;
    cin >> ans;
    res[3] = sqrt(ans);
    
    cout << "? 5 5" << endl;
    cin >> ans;
    res[4] = sqrt(ans);

    for(int num : nums) {
        bool found = false;
        for(int i = 0; i < 5; i ++) {
            if(res[i] == num) { found = true; break; }
        }
        if(!found) {
            res[5] = num;
            break;
        }
    }
    cout << "! ";
    for(int i = 0; i < 6; i ++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
15 23 8 4 16 42
*/

/*
23 15 8 4 16 42
*/

/*
4 16 8 23 42 15
*/