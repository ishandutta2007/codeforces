// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
string s;
ll n, k, chl=1;
string one(){
    string s2 = s;
    chl=0;
    for(ll i = 0;i<n;i++){
        ll e0 = s[(i-1+n)%n]=='W'?1:0;
        ll e1 = s[i]=='W'?1:0;
        ll e2 = s[(i+1)%n]=='W'?1:0;
        if(e0+e1+e2>=2) s2[i]='W';
        else s2[i]='B';
        if(s[i]!=s2[i]) chl++;
    }
    return s2;
}
bool odin[N];
ll ps[N];
bool ban[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n >> k;
    cin >> s;
    ll oc=0;
    for(ll i = 0;i<n;i++){
        ll e0 = s[(i-1+n)%n]=='W'?1:0;
        ll e1 = s[i]=='W'?1:0;
        ll e2 = s[(i+1)%n]=='W'?1:0;
        if(e1!=e0&&e1!=e2) odin[i]=1, oc++;
    }
    if(oc==n){
        if(k&1) s=one();
        cout<<s<<'\n';
        return 0;
    }
    ll wp=n-1;
    while(odin[wp]) --wp;
    for(ll i = (wp+1)%n, j=0;j<n;j++, i=(i+1)%n){
        if(odin[i]) ps[i]=ps[(i+n-1)%n]+1;
        else ps[i]=0;
    }
    wp=0;
    while(odin[wp]) ++wp;
    for(ll i = (wp-1+n)%n, j=0;j<n;j++, i=(i-1+n)%n){
        if(odin[i]) ps[i]=min(ps[i], ps[(i+1)%n]+1);
    }
    ll p2=wp;
    ban[wp]=1;
    while(true){
        bool cd=1;
        while(!odin[p2]){
            p2=(p2+1)%n;
            if(ban[p2]){
                cd=0;
                break;
            }
            ban[p2]=1;
        }
        if(!cd) break;
        ll p1=p2;
        while(odin[p2]){
            p2=(p2+1)%n;
            if(ban[p2]&&odin[p2]){
                cd=0;
                break;
            }
            ban[p2]=1;
        }
        if(!cd) break;
        ll p3=p2;
        p2=(p2+n-1)%n;
        ll us = (p1<=p2?p2-p1+1:n-p1+p2+1);
        for(ll op=0;op<k&&us>0;op++){
            odin[p1]=0, odin[p2]=0;
            if(p1<=p2){
                s[p1]=s[(p1+n-1)%n];
                s[p2]=s[(p2+1)%n];
                ++p1, p2--;
                us-=2;
            }else{
                s[p1]=s[(p1+n-1)%n];
                s[p2]=s[(p2+1)%n];
                p1=(p1+1)%n;
                p2=(p2+n-1)%n;
                us-=2;
            }
        }
        p2=p3;
    }
    for(ll i = 0;i<n;i++){
        if(odin[i]&&k%2==1){
            s[i]=(s[i]=='W'?'B':'W');
        }
    }
    cout<<s;
}