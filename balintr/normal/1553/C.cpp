#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

int t;

int calc(string str){
    int a = 0;
    int b = 0;
    int aLeft = 5;
    int bLeft = 5;
    for (int i = 0; i < 10; ++i) {
        if(i % 2){
            aLeft--;
            a += str[i] == '1';
        }
        else {
            bLeft--;
            b += str[i] == '1';
        }
        if(a + aLeft < b || b + bLeft < a) return i+1;
    }
    return 10;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        string str;
        cin >> str;

        string str1 = str;
        string str2 = str;
        for (int i = 0; i < 10; ++i) {
            if(str[i] == '?'){
                if(i % 2){
                    str1[i] = '1';
                    str2[i] = '0';
                }
                else {
                    str2[i] = '1';
                    str1[i] = '0';
                }
            }
        }

        cout << min(calc(str1), calc(str2)) << '\n';
    }
}