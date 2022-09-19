#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1048576 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll a[MAXN];
ll b[MAXN];
ll in[21];
ll in2[21];
ll ma[21];



ll po, ii, jj, cnt = 0;
void merg(ll l, ll mid, ll r, ll lev){
    //cerr << "start" << endl;
    //for(int i = l; i <= r; i++) cerr << a[i] << " ";
    //cerr << endl;


    reverse(a + l,a + r + 1);
    reverse(a + l, a + mid + 1);
    reverse(a + mid + 1, a + r + 1);

    po = 0;
    ii = l;
    jj = mid + 1;
    while((ii <= mid) and (jj <= r)){
        if(a[ii] > a[jj]){
            //b[po] = a[jj];
            jj ++;
            in2[lev] += (mid - ii + 1);
            /*debug(ii);
            debug(lev);
            debug(mid);*/
        } else {
            //b[po] = a[ii];
            ii ++;
        }
        po++;
        //cout << ii << " " << jj << "   ";
    }

    reverse(a + l,a + r + 1);
    reverse(a + l, a + mid + 1);
    reverse(a + mid + 1, a + r + 1);



    po = 0;
    ii = l;
    jj = mid + 1;
    while((ii <= mid) and (jj <= r)){
        if(a[ii] > a[jj]){
            b[po] = a[jj];
            jj ++;
            in[lev] += (mid - ii + 1);
            /*debug(ii);
            debug(lev);
            debug(mid);*/
        } else {
            b[po] = a[ii];
            ii ++;
        }
        po++;
        //cout << ii << " " << jj << "   ";
    }

    //cout << endl;
    for(int i = ii; i <= mid; i++){
        b[po] = a[i];
        po++;
    }
    for(int i = jj; i <= r; i++){
        b[po] = a[i];
        po++;
    }
    //cout << po << " " << l << " " << r << " " << mid << endl;
    //for(int i = 0; i < po; i++) cerr << b[i] << " ";
    //cerr << endl;
    for(int i = 0;i < po;i++){
        a[l + i] = b[i];
        //cout << b[i] << " ";
    }
    //cout << endl;
}
void merge_sort(ll l, ll r, ll lev){
    if(l == r)return ;
    merge_sort(l, (l + r) / 2, lev - 1);
    merge_sort((l + r) / 2 + 1, r, lev - 1);
    merg(l, (l + r) / 2, r, lev);
}

ll fl[21];

int main(){
    ios::sync_with_stdio(0);
    ll n, no;
    scanf("%lld", &n);
    ll m = (1ll << n);
    for(int i = 0; i < m; i++) scanf("%lld", &a[i]);

    ma[0] = 0;
    no = m;
    ll ch = 1;
    for(int i = 1; i <= n; i++){
        no /= 2;
        ma[i] = no * (ch * ch);
        ch *= 2;
    }

    //reverse(ma, ma + n + 1);

    //for(int i = 0; i <= n; i++) debug(ma[i]);

    merge_sort(0, m - 1, n);

    //for(int i = 1; i <= n; i++) in[i] += in[i-1];

    for(int i = 0; i <= n; i++) debug(in[i]);
    for(int i = 0; i <= n; i++) debug(in2[i]);

    ll q, qq, out;
    scanf("%lld", &q);
    for(int i = 0; i < q; i++){
        scanf("%lld", &qq);

        for(int j = 0; j <= qq; j++) fl[j] = 1 - fl[j];
        out = 0;
        for(int j = 0; j <= n; j++) {
            if(fl[j] == 0)out += in[j];
            else out += in2[j];
        }
        printf("%lld\n", out);
    }
    return 0;
}

/*
*/