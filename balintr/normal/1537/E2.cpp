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
#define sc second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}

int n, k;
string str;

int main(){
    boost();
    cin >> n >> k >> str;
    str.push_back('z'+1);
    int trimLen = n;
    int j = 0;
    bool checking = false;
    for (int i = 1; i <= n; ++i) {
        if(checking) {
            if(str[++j] > str[i]){
                checking = false;
                j = 0;
            }
            else if(str[j] < str[i]){
                trimLen = i - j;
                break;
            }
        }
        if(!checking){
            if(str[i] > str[0]){
                trimLen = i;
                break;
            }
            if(str[i] == str[0]) checking = true;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << str[i % trimLen];
    }
    cout << '\n';
}