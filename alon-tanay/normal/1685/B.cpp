#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define ld long double
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

int DEBUG_INDENT = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string str;
        cin >> str;
        int n = str.length();
        int ac = 0;
        for(int i = 0; i < n; i ++) {
            ac += (str[i] == 'A');
        }
        if(ac != a + c + d) {
            cout << "NO\n";
            continue;
        }
        int cnt = 0;
        int st = 0;
        vector<int> AB;
        vector<int> BA;
        int free_sum = 0;
        for(int i = 1; i < n; i ++) {
            if(str[i] != str[i-1]) {
                cnt ++;
            } else {
                if(cnt) {
                if((cnt&1)==0) {
                    free_sum += cnt/2;
                } else {
                    if(str[st] == 'A') {
                        AB.push_back(cnt);
                    } else {
                        BA.push_back(cnt);
                    }
                }
                }
                st = i;
                cnt = 0;
            }
        }
        if(cnt) {
        if((cnt&1)==0) {
            free_sum += cnt/2;
        } else {
            if(str[st] == 'A') {
                AB.push_back(cnt);
            } else {
                BA.push_back(cnt);
            }
        }
        }
        sort(AB.begin(),AB.end());
        sort(BA.begin(),BA.end());
        // cout << "sum: " << free_sum << "\n";
        // for(int ff : AB) {
        //     cout << ff << " ";
        // }
        // cout << "\n";
        // for(int ff : BA) {
        //     cout << ff << " ";
        // }
        // cout << "\n";
        for(int sz : AB) {
            if(c >= (sz+1)/2) {
                c -= (sz+1)/2;
            } else {
                d -= ((sz)/2-c);
                d = max(d,0);
                c = 0;
            }
        }
        for(int sz : BA) {
            if(d >= (sz+1)/2) {
                d -= (sz+1)/2;
            } else {
                c -= ((sz)/2-d);
                c = max(c,0);
                d = 0;
            }
        }
        if(c+d <= free_sum) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
1
1 1 2 3
ABABABBAABAB

AB:6
BA:2
AB:4
*/