#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

//#pragma GGC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, int> pii;
const int N=300005;
int tab[N], ans[N], tab4[N], K, L, rep[N], ile[N];
pii tab2[10];
pair<pii, pii > tab3[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(247356945);
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        cin>>tab[i];
        ile[tab[i]]++;
    }
    const int T=10;
    K=300;
    L=550;
    int wsk=0;
    set<int> S;
    for(int i=0; i<q; i++){
        int l, r, k;
        cin>>l>>r>>k;
        l--;
        r--;
        if((r-l+1)/k>K){
            //cout<<"a";
            tab3[wsk++]={{l, r}, {k, i}};
            for(int j=0; j<T; j++){
                int x=tab[l+rand()%(r-l+1)];
                //cout<<x<<" "<<ile[x]<<"\n";
                if(ile[x]>=K) S.insert(x);
            }
        }
        else{
            //cout<<"b";
            for(int j=l; j<=r; j++){
                bool b=0;
                for(int h=1; h<k; h++){
                    if(tab[j]==tab2[h].st){
                        tab2[h].nd++;
                        b=1;
                        break;
                    }
                }
                if(!b){
                    for(int h=k-1; h>0; h--){
                        if(tab2[h].nd==0){
                            tab2[h].nd=1;
                            tab2[h].st=tab[j];
                            b=1;
                            break;
                        }
                    }
                }
                if(!b){
                    for(int h=1; h<k; h++){
                        tab2[h].nd--;
                    }
                }
                //cout<<tab2[0].st<<" "<<tab2[0].nd<<" "<<tab2[1].st<<" "<<tab2[1].nd<<"\n";
            }
            int mini=N;
            //cout<<"a";
            for(int h=1; h<k; h++){
                if(tab2[h].nd!=0){
                    int cnt=0;
                    for(int j=l; j<=r; j++){
                        if(tab[j]==tab2[h].st)   cnt++;
                    }
                    //cout<<cnt*k;
                    if((cnt*k)>(r-l+1))  mini=min(tab2[h].st, mini);
                }
                tab2[h].st=0;
                tab2[h].nd=0;
            }
            ans[i]=mini;
        }
    }
    for(int i=0; i<=n; i++){
        rep[i]=N-1;
    }
    vector<int> V;
    for(int i:S){
        //cout<<i<<"\n";
        rep[i]=V.size();
        V.push_back(i);
    }
    sort(tab3, tab3+wsk, [](pair<pii, pii> a, pair<pii, pii> b){if(a.st.st/L!=b.st.st/L)    return a.st.st/L<b.st.st/L;  return a.st.nd<b.st.nd;});
    int l=0, r=0;
    //cout<<wsk<<"\n";
    for(int i=0; i<wsk; i++){
        //cout<<tab3[i].st.nd<<" "<<tab3[i].st.st<<"\n";
        while(r<=tab3[i].st.nd){
            tab4[rep[tab[r++]]]++;
        }
        while(l<tab3[i].st.st){
            tab4[rep[tab[l++]]]--;
        }
        while(l>tab3[i].st.st){
            tab4[rep[tab[--l]]]++;
        }
        while(r!=tab3[i].st.nd+1){
            tab4[rep[tab[--r]]]--;
        }
        for(int j=0; j<V.size(); j++){
            //cout<<tab4[j];
            if(tab4[j]*tab3[i].nd.st>r-l){
                //cout<<r<<l<<" "<<V[j]<<"\n";
                /*if((tab3[i].nd.nd+1)==254645){
                    cout<<"a";
                }*/
                ans[tab3[i].nd.nd]=V[j];
                break;
            }
        }
    }
    for(int i=0; i<q; i++){
        if(ans[i]==0 or ans[i]==N)   cout<<"-1\n";
        else    cout<<ans[i]<<"\n";
    }
}