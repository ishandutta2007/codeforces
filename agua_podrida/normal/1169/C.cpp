#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<bool> vbool;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end; ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int i = 1; i <= n; i++)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first;
#define S second;

void a(){
    int n,a,b,x,y;
    cin>>n>>a>>x>>b>>y;
    while(a != b && a != x && b != y){
        a++;
        if(a==n+1) a = 1;
        b--;
        if(b == 0) b = n;
    }
    if(a == b){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

bool estosSirven(vi& x, vi& y, int xprov, int yprov, int m){
    int i = 0;
    while(i < m && (x[i] == xprov || y[i] == xprov || x[i] == yprov || y[i] == yprov)) i++;
    return i == m;
}

void b(){
    int n, m;
    cin>>n>>m;
    vi x(m);
    vi y(m);
    F0(i,m)
        cin>>x[i]>>y[i];

    int xprov = x[0];
    int i = 0;
    while(i < m && (x[i] == xprov || y[i] == xprov)) i++;
    if(i == m){
        cout<<"YES"<<endl;
        return;
    }
    int yprov = x[i];
    if(estosSirven(x,y,xprov,yprov,m)){
        cout<<"YES"<<endl;
        return;
    }
    yprov = y[i];
    if(estosSirven(x,y,xprov,yprov,m)){
        cout<<"YES"<<endl;
        return;
    }

    xprov = y[0];
    i = 0;
    while(i < m && (x[i] == xprov || y[i] == xprov)) i++;
    if(i == m){
        cout<<"YES"<<endl;
        return;
    }
    yprov = x[i];
    if(estosSirven(x,y,xprov,yprov,m)){
        cout<<"YES"<<endl;
        return;
    }
    yprov = y[i];
    if(estosSirven(x,y,xprov,yprov,m)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

bool esCreciente(vi& a){
    int i = 0;
    while(i < a.size()-1 && a[i] <= a[i+1]) i++;
    return i == a.size()-1;
}

void llevarAlMinimoAlcanzable(int& ai, int mid, int m, int lower){
    if(ai + mid >= m && ai+mid-m >= lower) ai = lower;
    else if(ai < lower && ai + mid >= lower) ai = lower;
}

bool sirve(vi a, int mid, int m){
    int lower = 0;
    F0(i,a.size()){
        llevarAlMinimoAlcanzable(a[i],mid,m,lower);
        lower = a[i];
    }
    return esCreciente(a);
}

void c(){
    int n, m;
    cin>>n>>m;
    vi a(n);
    F0(i,n) cin>>a[i];
    if(esCreciente(a)) {
        cout<<'0'<<endl;
        return;
    }
    int lo = 0;
    int hi = m-1;
    while(lo != hi-1){
        int mid = (lo+hi)/2;
        if(sirve(a,mid,m)) hi = mid;
        else lo = mid;
    }
    cout<<hi<<endl;
}

int main() {
    c();
    return 0;
}