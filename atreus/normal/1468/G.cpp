#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pld;

const int maxn = 2e5 + 10;

ld operator * (pld a, pld b){
    return 1ll * a.F * b.S - 1ll * a.S * b.F;
}
ld operator ^ (pld a, pld b){
    return 1ll * a.F * b.F + 1ll * a.S * b.S;
}
pld operator - (pld a, pld b){
    return {a.F - b.F, a.S - b.S};
}
pld operator + (pld a, pld b){
    return {a.F + b.F, a.S + b.S};
}

pld p[maxn];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int n, H;
    cin >> n >> H;
    for(int i = 0; i < n; i++){
	int a, b;
	cin >> a >> b;
	p[i] = {a, b};
    }
    p[n] = {p[n-1].F, p[n-1].S + H};
    pii see = p[n-1];
    ld ans = 0;
    for(int i = n-2; i >= 0; i--){
	pld X = see - p[n];
	pld Y = p[i+1] - p[i];
	if(X * (p[i]-p[n]) <= 0){
	    //	    cout << "HYE " << i << endl;
	    //	    p[n] + X * alpha == p[i] + Y * gama;
	    //      p[n] * X == p[i] * X + Y * X * gama
	    if(X * Y == 0){
		ans+= sqrt(Y ^ Y);
	    }
	    else{		
		ld gama = (p[n] * X - p[i] * X) / (Y * X);
		ans+= sqrt(Y ^ Y) * abs(gama);
	    }
	    see = p[i];
	}	    
    }
    return cout << setprecision(12) << ans << endl, 0;
}