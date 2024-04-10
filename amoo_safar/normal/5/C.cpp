#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = (ll) 1e6 + 10;

stack<ll> s;

ll f[MAXN];
ll l[MAXN];


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string t;
    getline(cin, t);
    fill(f, f+MAXN,-1);
    fill(l, l+MAXN,-1);
    ll he;
    f[0] = 0;
    for(int i = 0;i < t.size(); i++){
        if(s.size() == 0){
            s.push(i + 1);
        } else {
            if((t[s.top()-1] != t[i]) and (t[i] == ')'))s.pop();
            else s.push(i + 1);
        }

        if(s.size() == 0)he = 0;
        else he = s.top();
        if(f[he] == -1)f[he] = i + 1;
        l[he] = i + 1;
    }
    /*for(int i = 0;i<=t.size();i++)cerr << f[i] << " ";
    cerr << endl;
    for(int i = 0;i<=t.size();i++)cerr << l[i] << " ";
    cerr << endl;*/
    ll m = 0;
    ll cnt = 1;
    for(int i = 0; i < MAXN; i++){
        if(f[i] == -1)continue;
        if(l[i] - f[i] > m){
            m = l[i] - f[i];
            cnt = 1;
        } else if(l[i] - f[i] == m){
            cnt ++;
        }
    }
    if(m == 0)cout << "0 1" << endl;
    else cout << m << " " << cnt  << endl;
    return 0;
}