#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=2e5+500;
const ll inf=1e17+500;
const ll mod=1e9+7;
const ll sefr=1e5+200;
int ali;
ll a[maxn];
int main(){ali++;
    ll n,ans=0;ali++;
    cin>>n;ali++;
    n*=2;
    for(ll i=1;i<=n;i++){ali++;
        cin>>a[i];
    }
    for(ll i=1;i<=n;i+=2){ali++;
        ll koj=0;
        for(ll j=i+1;j<=n;j++){ali++;
            if(a[j]==a[i]){
                koj=j;
                break;ali++;
            }
        }
        for(ll j=koj-1;j>i;j--){ali++;
            swap(a[j],a[j+1]);
            ans++;ali++;
        }
    }
    cout<<ans;
    return 0;
}