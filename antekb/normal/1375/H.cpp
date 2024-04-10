#include<bits/stdc++.h>
using namespace std;
int n;
const int N=(1<<12)+5, K=(1<<8)+5;
int tab[N], tab2[N][K], tab3[N];
vector<pair<int, int > > state;
vector<int> V[K];
vector<vector<int> > dp[K];
vector<vector<int> > gen(vector<int> vec, int l, int r){
    //cout<<l<<" "<<r<<"\n";
    if(l==r){
        vector<vector<int> > res(1);
        res[0].push_back(tab3[l]);
        return res;
    }
    int m=(l+r)/2;
    vector<int> V1, V2;
    for(int i:vec){
        if(i<=m)V1.push_back(i);
        else V2.push_back(i);
    }
    vector<vector<int> > res1=gen(V1, l, m), res2=gen(V2, m+1, r), res(n);
    int p1=0, p2=0, k1=0, k2=0;
    //cout<<" - "<<l<<" "<<r<<" "<<vec[0]<<" "<<vec[1]<<"\n";
    for(int i=0; i<vec.size(); i++){
        //cout<<"a";

        for(int j=i; j<vec.size(); j++){
            //cout<<"b";
            if(vec[j]<=m)k1++;
            else k2++;
            if(p1==k1){res[i].push_back(res2[p2][k2-p2-1]);}
            else{ if(p2==k2){res[i].push_back(res1[p1][k1-p1-1]);}
            else{
                //cout<<"x";
                //cout<<p1<<" "<<k1<<" "<<p2<<" "<<k2<<"\n";
                state.push_back({res1[p1][k1-p1-1], res2[p2][k2-p2-1]});
                //cout<<"y";
                res[i].push_back(state.size()+n);
            }}
            //cout<<"c";
        }
        if(vec[i]<=m)p1++;
        else p2++;
        k1=p1;
        k2=p2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    int k=(1<<8), t=(n+k-1)/k;
    for(int i=0; i<n; i++){
        cin>>tab[i];
        tab[i]--;
        tab3[tab[i]]=i+1;
        V[tab[i]/k].push_back(tab[i]);
        for(int j=0; j<t; j++){
            tab2[i+1][j]=tab2[i][j];
        }
        tab2[i+1][tab[i]/k]++;
    }
    /*cout<<"\n\n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<t; j++){
            cout<<tab2[i][j]<<" \n"[j==t-1];
        }
    }
    cout<<"\n\n";*/
    for(int i=0; i<t; i++){
        dp[i]=gen(V[i], i*k, min(n-1, k*(i+1)-1));
    }
    vector<int> ans;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        int act=-1;
        for(int i=0; i<t; i++){
            if(tab2[l][i]!=tab2[r][i]){
                if(act==-1)act=dp[i][tab2[l][i]][tab2[r][i]-tab2[l][i]-1];
                else{
                    //cout<<"l"<<tab2[l][i]<<" "<<tab2[r][i]-tab2[l+1][i]<<"\n";
                    state.push_back({act, dp[i][tab2[l][i]][tab2[r][i]-tab2[l][i]-1]});
                    act=state.size()+n;
                }
            }
        }
        ans.push_back(act);
    }
    cout<<state.size()+n<<"\n";
    for(auto i:state){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}