#include<bits/stdc++.h>
using namespace std;
const int N=(1<<17), mod=(1e9+7);
long long base=10, odw=(mod+1)/9;
int tab[2*N], lazy[2*N], siz[2*N];
long long pot[N];
void propagate(int v){
    if(v>=N || lazy[v]==-1)    return;
    int l=v<<1, r=l^1;
    lazy[r]=lazy[v];
    lazy[l]=lazy[v];
    tab[l]=((pot[siz[l]]-1)*odw*lazy[v])%mod;
    tab[r]=tab[l];
    lazy[v]=-1;
}
void tworz(string t){
    for(int i=0; i<t.size(); i++){
        tab[N+i]=(t[i]-'0');
    }
    for(int i=2*N-1; i>=N; i--){
        siz[i]=1;
        lazy[i]=-1;
    }
    for(int i=N-1; i>0; i--){
        siz[i]=2*siz[2*i];
        lazy[i]=-1;
        tab[i]=(tab[2*i]+pot[siz[2*i]]*tab[2*i+1])%mod;
    }
}
void update(int v, int l, int r, int a, int b, int c){
    //cout<<v<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<tab[v]<<" "<<tab[2*v]<<" "<<tab[2*v+1]<<" "<<siz[v]<<" "<<pot[siz[v]/2]<<" "<<lazy[v]<<"\n";
    if(l==a && r==b){
        lazy[v]=c;
        tab[v]=((pot[siz[v]]-1)*odw*c)%mod;
        //cout<<v<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<tab[v]<<" "<<tab[2*v]<<" "<<tab[2*v+1]<<" "<<siz[v]<<" "<<pot[siz[v]/2]<<" "<<lazy[v]<<"\n";
        return;
    }
    propagate(v);
    int m=(l+r)/2;
    if(a<=m){
        update(2*v, l, m, a, min(b, m), c);
    }
    if(b>m){
        update(2*v+1, m+1, r, max(a, m+1), b, c);
    }
    tab[v]=(tab[2*v]+pot[siz[v]/2]*tab[2*v+1])%mod;
    //cout<<v<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<tab[v]<<" "<<tab[2*v]<<" "<<tab[2*v+1]<<" "<<siz[v]<<" "<<pot[siz[v]/2]<<" "<<lazy[v]<<"\n";
    return;
}
long long  ans(int v, int l, int r, int a, int b){
    //cout<<v<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<tab[v]<<" "<<tab[2*v]<<" "<<tab[2*v+1]<<" "<<siz[v]<<" "<<pot[siz[v]/2]<<" "<<lazy[v]<<"\n";
    if(l==a && r==b){
        return tab[v];
    }
    propagate(v);
    int m=(l+r)/2;
    long long res=0;
    if(a<=m){
        res=ans(2*v, l, m, a, min(b, m));
    }
    if(b>m){
        res+=(pot[m+1-min(a, m+1)]*ans(2*v+1, m+1, r, max(a, m+1), b))%mod;
    }
    return res%mod;
}
bool czy(int l, int r, int d){
    if(l+d>r)   return 1;
    return ((ans(1, 0, N-1, l, r-d))==(ans(1, 0, N-1, l+d, r)));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout<<
    pot[0]=1;
    for(int i=1; i<N; i++){

        pot[i]=(pot[i-1]*10)%mod;
    //if(i<10)cout<<pot[i]<<"\n";
    }
    int n, m, k;
    cin>>n>>m>>k;
    string t;
    cin>>t;
    tworz(t);
    for(int i=0; i<m+k; i++){
        int t, l, r, d;
        cin>>t>>l>>r>>d;
        l--;
        r--;
        if(t==2){
            if(czy(l, r, d))    cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            update(1, 0, N-1, l, r, d);
        }
    }
    //cout<<ans(1, 0, N-1, 1, 1);
}