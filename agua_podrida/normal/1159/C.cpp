#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); (i) <=(b); (i)++)
#define F1(i,n) for(int i = 1; (i)<= (n);(i)++)
#define F0(i,n) for(int i = 0; (i)< (n);(i)++)
#define forall(it,s) for(auto it = s.begin(); it != s.end(); it++)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define  F first
#define S second
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

void a(){
    int n;
    cin>>n;
    int minimo = 0;
    int cuenta = 0;
    string s;
    cin>>s;
    F0(i,n){
        if(s[i] == '+')
            cuenta++;
        else
            cuenta--;
        minimo = min(minimo,cuenta);
    }
    cout<<cuenta-minimo<<'\n';
}

void b(){
    int n;
    cin>>n;
    vector<int> v(n);
    F0(i,n){
        cin>>v[i];
    }
    int res = 2000000000;
    F0(i,n){
        int maxDist = max(i,n-i-1);
        res = min(res,v[i]/maxDist);
    }
    cout<<res<<'\n';
}

void c(){
    int n,m;
    cin>>n>>m;
    vll boys(n);
    vll girls(m);
    F0(i,n)
        cin>>boys[i];
    F0(i,m)
        cin>>girls[i];
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    if(boys.back() > girls[0]){
        cout<<-1<<'\n';
        return;
    }
    ll regalados = 0;
    F0(i,n){
        regalados += boys[i]*m;
    }
    if(n == 1 && boys.back() != girls[0]){
        cout<<-1<<'\n';
        return;
    }
    F1(i,m-1){
        regalados += girls[i] - boys.back();
    }
    if(girls[0] != boys.back()) regalados += girls[0] - boys[n-2];
    cout<<regalados<<'\n';
}

int main(){
    c();
    return 0;
}