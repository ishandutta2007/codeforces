#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;

int n;
vector < int > v;
bool is_p[1000100];


bool is_prime(int n){
    int c = 0;
    while( v[c] * v[c] <= n){
        if(n % v[c] == 0) return 0;
        c++;
    }
    return 1;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    for(int i = 2; i < 1000000; i++){
        if(!is_p[i] ){
            v.pb( i );
            if( i * 1ll * i <= 1000000){
                for(int j = i * i; j <= 1000000; j += i)
                    is_p[j] = 1;
            }
        }
    }
    cin >> n;
    if( is_prime(n)){
        cout << 1 << endl << n << endl;
        return 0;
    }
    if( is_prime(n-3)){
        cout << 2 << endl << n-3<< " " << 3 << endl;
        return 0;
    }
    n -= 3;
    for(int x: v){                         
        if( is_prime( n - x)){
            cout << "3\n3 " << n - x << " "<< x << endl;
            return 0;
        }
    }

        
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}