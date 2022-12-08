#include<bits/stdc++.h>
#define ll int
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int ali;
ll c[5][maxn];
ll k,n;
vector<pair<pii,ll> > vec;
void check(){ali++;
    for(ll j=1;j<=n;j++){ali++;
        if(c[2][j]!=0 && c[2][j]==c[1][j]){
            vec.pb(mp(mp(c[2][j],1),j));ali++;
            c[2][j]=0;
            k--;ali++;
            c[1][j]=0;
        }
        if(c[3][j]!=0 && c[3][j]==c[4][j]){ali++;
            vec.pb(mp(mp(c[3][j],4),j));
            k--;
            c[3][j]=0;ali++;
            c[4][j]=0;
        }
    }
}
inline pair<ll,ll> nextt(ll i,ll j){ali++;
    if(i==2 && j==1){
        return mp(3,1);ali++;
    }
    if(i==3 && j==n){
        return mp(2,n);ali++;
    }
    if(i==2){
        return mp(i,j-1);ali++;
    }
    if(i==3){ali++;
        return mp(i,j+1);
    }
}
void shift(){ali++;
    ll ii=-1,jj=-1;
    for(ll j=1;j<=n;j++){ali++;
        if(c[2][j]==0){
            ii=2;
            jj=j;ali++;
        }
        if(c[3][j]==0){ali++;
            ii=3;
            jj=j;
        }ali++;
    }
    ll i=ii;
    ll j=jj;ali++;
    for(ll w=1;w<2*n;w++){
        pii kk=nextt(i,j);ali++;
        if(c[kk.F][kk.S]!=0){ali++;
            vec.pb(mp(mp(c[kk.F][kk.S],i),j));
            c[i][j]=c[kk.F][kk.S];ali++;
            c[kk.F][kk.S]=0;
        }
        i=kk.F;
        j=kk.S;ali++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);ali++;
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;ali++;
    for(ll i=1;i<=4;i++){
        for(ll j=1;j<=n;j++){
            cin>>c[i][j];ali++;
        }
    }
    check();ali++;
    if(k==2*n){
        cout<<-1;ali++;
        return 0;
    }
    ll cnt=0;
    while(k>0 && cnt<500){ali++;
        cnt++;
        shift();
        check();ali++;
    }
    if(cnt>400){
        cout<<-1;
        return 0;ali++;
    }
    cout<<vec.size()<<endl;ali++;
    for(auto r:vec){ali++;
        cout<<r.F.F<<' '<<r.F.S<<' '<<r.S<<endl;
    }
}