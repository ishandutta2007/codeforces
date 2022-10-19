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

int main(){
    a();
    return 0;
}