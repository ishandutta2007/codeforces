#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

char akel_sosat[1001][1001];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    string a;
    cin >> a;
    ll kol = 0, mx = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '[')kol++;
        else kol--;
        mx = max(mx, kol);
    }
    ll m = mx * 2 + 3;
    ll l = 1, len = mx;
    for(int i = 1; i <= 1000; i++)
        for(int j = 0; j < 1001; j++)akel_sosat[i][j] = ' ';
    ll st = 0;
    for(int i = 0; i < n; i++, st++){
        if(a[i] == '['){
            akel_sosat[l][st] = '+';
            akel_sosat[l][st + 1] = '-';
            ll l1 = len * 2 - 1;
            for(int j = l + 1; j <= l + l1; j++)akel_sosat[j][st] = '|';
            akel_sosat[l + l1 + 1][st] = '+';
            akel_sosat[l + l1 + 1][st + 1] = '-';
            len--;
            l++;
        }else {
            if(a[i] != a[i - 1])st += 3;
            l--;
            len++;
            akel_sosat[l][st] = '+';
            akel_sosat[l][st - 1] = '-';
            ll l1 = len * 2 - 1;
            for(int j = l + 1; j <= l + l1; j++)akel_sosat[j][st] = '|';
            akel_sosat[l + l1 + 1][st] = '+';
            akel_sosat[l + l1 + 1][st - 1] = '-';
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < st; j++)cout << akel_sosat[i][j];
        cout << "\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}