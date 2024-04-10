// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll get(string s){
    if(s=="C") return 0;
    if(s=="C#") return 1;
    if(s=="D") return 2;
    if(s=="D#") return 3;
    if(s=="E") return 4;
    if(s=="F") return 5;
    if(s=="F#") return 6;
    if(s=="G") return 7;
    if(s=="G#") return 8;
    if(s=="A") return 9;
    if(s=="B") return 10;
    if(s=="H") return 11;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    ll a = get(s1), b=get(s2), c=get(s3);
    vector<ll> e{a, b, c};
    sort(e.begin(), e.end());
    do{
        ll d1 = (e[1]-e[0]+12)%12, d2 = (e[2]-e[1]+12)%12;
        if(d1==3&&d2==4) return cout<<"minor", 0;
        if(d1==4&&d2==3) return cout<<"major", 0;
    }while(next_permutation(e.begin(), e.end()));
    cout<<"strange";
}