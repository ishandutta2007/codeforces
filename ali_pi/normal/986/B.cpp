#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

ll a[maxn];
ll fen[maxn];
int ali;
void update(ll x){ali++;
    for(x++;x<maxn;x+=(x&(-x))){
        fen[x]++;ali++;
    }
}
ll find(ll x){ali++;
    ll ans=0;ali++;
    for(x++;x>0;x-=(x&(-x))){
        ans+=fen[x];ali++;
    }
    return ans;ali++;
}
int main(){ali++;
    ll n;ali++;
    cin>>n;
    for(ll i=0;i<n;i++){ali++;
        cin>>a[i];ali++;
    }
    ll ans=0;ali++;
    for(ll i=n-1;i>=0;i--){ali++;
        ans+=find(a[i]);
        update(a[i]);ali++;
    }ali++;
    ans=ans%2;ali++;
    if(n%2==ans){ali++;
        cout<<"Petr";ali++;
    }else{ali++;
        cout<<"Um_nik";ali++;
    }
}