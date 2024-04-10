#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define size(n) ( int( n.size() ) )
#define sqr(n) ( (n) * (n) )
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5000;
int mod, fact[N], c[N], phi, prc[N], pwra[N];


int rev( int x ){
    int pwr[40];
    pwr[0] = x;
    for ( int i = 1; i < 35; i++ ){
        pwr[i] = ( pwr[i-1] * 1ll * pwr[i-1] ) % mod;
    }
    int res = 1, v = phi - 1;
    for ( int j = 30; j >= 0; j-- ){
        int bit = ( v >> j ) & 1;
        if ( bit ){
            res = ( res * 1ll * pwr[j] ) % mod;
        }
    }
    return res;
}

int getC( int n, int k ){
    int res = ( fact[n] * 1ll * rev( fact[k] ) ) % mod;
    res = ( res * 1ll * rev( fact[n-k] ) ) % mod;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, m, a, q;
    scanf("%d %d %d %d",&n,&m,&a,&q);


    int rem = 1;
    pwra[0] = 1;
    for ( int i = 1; i <= 1e6 + 500; i++ ){
        rem = ( rem * 1ll * a ) % q;
        pwra[i] = rem;
        if ( rem == 1 ){
            mod = i;
            break;
        }
    }
    fact[0] = 1;
    for ( int i = 1; i < N; i++ ){
        fact[i] = ( fact[i-1] * 1ll * i ) % mod;
    }
    phi = mod - 1;
    c[0] = 1;
    prc[0] = 1;
    for ( int i = 1; i <= m; i++  ){
        c[i] = getC( m, i );
        prc[i] = ( prc[i-1] + c[i] ) % mod;
    }

    for ( int i = 1; i <= n; i++ ){
        if ( i + m <= n ){
           printf("%d ",pwra[ prc[m] ]);
        }
        else{
            printf("%d ", pwra[ prc[n-i] ]);
        }
    }
    return 0;
}