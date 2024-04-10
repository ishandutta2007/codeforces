#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, int > pii;

const int N=5e5+5;
int tab[N], ile[N], mi[N], czy[N];
vector<int> dziel[N];
vector<pii> pie[N];
void gen(int id, int j, int pi, int sgn){
    //cout<<id<<" "<<j<<" "<<pi<<" "<<sgn<<"\n";
    if(j==pie[id].size()){
        if(pi==1){
            return;
        }
        dziel[id].push_back(pi);
        mi[pi]=sgn;
        return;
    }
    long long x=1;
    for(int i=0; i<=1/*pie[id][j].nd*/; i++){
        gen(id, j+1, pi*x, sgn*(1-2*(i%2)));
        x*=pie[id][j].st;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin>>n>>q;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        tab[i]=x;
        for(int j=2; j*j<=x; j++){
            if(x%j==0){
                int cnt=0;
                while(!(x%j)){
                    x/=j;
                    cnt++;
                }
                pie[i].push_back({j, cnt});
            }
        }
        if(x!=1){
            pie[i].push_back({x, 1});
        }
        gen(i, 0, 1, -1);
    }
    /*for(int i=0; i<n; i++){
        cout<<dziel[i].size()<<": ";
        for(int j:dziel[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
        for(auto j:pie[i]){
            cout<<j.st<<" ";
        }
        cout<<"\n";
    }*/
    int num=0;
    long long res=0;
    while(q--){
        int x;
        cin>>x;
        x--;
        //cout<<sgn<<" ";
        long long ans=0;
        for(int i:dziel[x]){
            if(czy[x])ile[i]--;
            ans+=ile[i]*mi[i];
            if(!czy[x])ile[i]++;
        }
        //cout<<ans<<" ";
        if(czy[x]){
            num--;
            res-=(num-ans);
        }
        else{
            res+=(num-ans);
            num++;
        }
        czy[x]^=1;
        cout<<res<<"\n";
    }
}