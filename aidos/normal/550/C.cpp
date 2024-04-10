#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' || s[i] == '8'){
            cout << "YES\n" << s[i] << endl;
            return 0;
        }
    }
    for(char c = '1'; c <= '9'; c++){
        for(char d = '1'; d <= '9'; d++){
            if(((c - '0') * 10 + (d-'0')) % 8 ) continue;
            int pos1 = -1;
            int pos2 = -1;
            for(int  i = 0; i < s.size(); i++){
                if(c == s[i]){
                    pos1 = i;
                    break;
                }
            }
            for(int i = pos1 + 1; i  < s.size(); i++){
                if(d == s[i]){
                    pos2 = i;
                    break;
                }
            }
            if(pos1==-1 || pos2 == -1) continue;
            cout << "YES\n";
            cout << c << d << endl;
            return 0;
        }
    }
    for(char k = '1'; k <= '9'; k++)
    for(char c = '1'; c <= '9'; c++){
        for(char d = '1'; d <= '9'; d++){
            if(((c - '0') * 10 + (d-'0') + (k - '0') * 100) % 8 ) continue;
            int pos3 = -1;
            int pos1 = -1;
            int pos2 = -1;
            for(int i = 0; i < s.size(); i++){
                if( k == s[i] ) {
                    pos3 = i;
                    break;
                }
            }
            for(int  i = pos3+1; i < s.size(); i++){
                if(c == s[i]){
                    pos1 = i;
                    break;
                }
            }
            for(int i = pos1 + 1; i  < s.size(); i++){
                if(d == s[i]){
                    pos2 = i;
                    break;
                }
            }
            if(pos1==-1 || pos2 == -1 || pos3 == -1) continue;
            cout << "YES\n";
            cout << k << c << d << endl;
            return 0;
        }
    }
    cout << "NO";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}