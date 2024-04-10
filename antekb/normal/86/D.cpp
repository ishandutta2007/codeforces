#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=1e6+5, K=500;
int tab[N], tab2[N];
long long ans[N];
typedef long long ll;
typedef pair<pair<int, int>, int> pii;
pii Q[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>tab[i];
    }
    for(int i=0; i<q; i++){
        cin>>Q[i].st.st>>Q[i].st.nd;
        Q[i].st.st--;
        Q[i].st.nd--;
        Q[i].nd=i;
    }
    sort(Q, Q+q, [](pii a, pii b){return (a.st.st/K!=b.st.st/K) ? a.st.st<b.st.st : a.st.nd<b.st.nd;});
    int l=0, r=0;
    long long res=0;
    for(int i=0; i<q; i++){
        while(r<=Q[i].st.nd){
            res+=(2*tab2[tab[r]]+1)*1ll*tab[r];
            tab2[tab[r]]++;
            r++;
        }
        while(r>Q[i].st.nd+1){
            r--;
            res-=(2*tab2[tab[r]]-1)*1ll*tab[r];
            tab2[tab[r]]--;
        }
        while(l<Q[i].st.st){
            res-=(2*tab2[tab[l]]-1)*1ll*tab[l];
            tab2[tab[l]]--;
            l++;
        }
        while(l>Q[i].st.st){
            l--;
            res+=(2*tab2[tab[l]]+1)*1ll*tab[l];
            tab2[tab[l]]++;
        }
        ans[Q[i].nd]=res;
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<"\n";
    }
}