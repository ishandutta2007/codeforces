#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=200005;
pair<pair<int, int>, int> tab[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--){
        int n, x=0, y=0;
        cin>>n;
        for(int i=1; i<=n; i++){
            char c;
            cin>>c;
            if(c=='U'){
                y++;
            }
            if(c=='R'){
                x++;
            }
            if(c=='D'){
                y--;
            }
            if(c=='L'){
                x--;
            }
            tab[i]={{x, y}, i};
        }
        tab[0]={{0, 0}, 0};
        sort(tab, tab+n+1);
        int ans=N, id=0;
        for(int i=0; i<n; i++){
            if(tab[i].st==tab[i+1].st and tab[i+1].nd-tab[i].nd<ans){
                ans=tab[i+1].nd-tab[i].nd;
                id=tab[i].nd;
            }
        }
        if(ans<N) cout<<id+1<<" "<<id+ans<<"\n";
        else cout<<"-1\n";
    }
}