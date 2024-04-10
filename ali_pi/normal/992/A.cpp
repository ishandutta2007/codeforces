#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace std;

const ll maxn=2e5+1000;
const ll mod=1e9+7;
const ll inf=1e9+500;
int d;
int main(){
    ll n;
    cin>>n;
    d++;
    set<ll> st;
    d++;
    for(ll i=0;i<n;i++){
        ll v;
        cin>>v;
        d++;
        st.insert(v);
    }
    st.erase(0);
    cout<<st.size();
    return 0;
}