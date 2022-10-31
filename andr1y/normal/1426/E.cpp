// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll n, ak0, an0, ab0, bk0, bn0, bb0;
ll cmax(){
    ll ak=ak0, an=an0, ab=ab0, bk=bk0, bn=bn0, bb=bb0;
    ll mk = min(ak, bn);
    ll mn = min(an, bb);
    ll mb = min(ab, bk);
    return mk+mn+mb;
}
ll cmin(){
    ll ak=ak0, an=an0, ab=ab0, bk=bk0, bn=bn0, bb=bb0, r = n;
    ll a[3] = {ak, an, ab};
    ll b[3] = {bk, bn, bb};
    ll ap[3] = {0, 1, 2};
    do{
        ll bp[3] = {0, 1, 2};
        do{
            ll stops[6] = {0, a[ap[0]], a[ap[0]]+a[ap[1]], n, b[bp[0]], b[bp[0]]+b[bp[1]]};
            sort(stops, stops+6);
            ll vl=0;
            for(ll i = 1;i<6;i++){
                ll l = stops[i-1]+1, r = stops[i];
                ll abv = (l>=1&&r<=a[ap[0]]?ap[0]:(l>=a[ap[0]]+1&&r<=a[ap[0]]+a[ap[1]]?ap[1]:ap[2]));
                ll bbv = (l>=1&&r<=b[bp[0]]?bp[0]:(l>=b[bp[0]]+1&&r<=b[bp[0]]+b[bp[1]]?bp[1]:bp[2]));
                if((abv+1)%3==bbv) vl+=r-l+1;
            }
            r=min(r, vl);
        }while(next_permutation(bp, bp+3));
    }while(next_permutation(ap, ap+3));
    return r;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	cin >> n >> ak0 >> an0 >> ab0 >> bk0 >> bn0 >> bb0;
    cout<<cmin()<<' '<<cmax()<<'\n';
}