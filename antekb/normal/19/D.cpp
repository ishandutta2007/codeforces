#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
const int N=(1<<18);
typedef pair<int, int> pii;
pair<pii, int> Q[N];
pair<pii, int> tab2[N];
pii tab4[N];
int tab[2*N], tab3[N], tab5[N];
void Set(int id, int x){
    //cout<<"b";
    tab[id+N]=x;
    for(id+=N; id>1; id>>=1){
        tab[id/2]=max(tab[id], tab[id^1]);
    }
}
int ans(int v, int x){
    //cout<<"a";
    for(v+=N; v>1; v/=2){
        //cout<<"t";
        //cout<<v<<
        if(!(v&1) && tab[v+1]>x){
            v++;
            while(v<N){
                //cout<<"z";
                v=2*v;
                if(tab[v]<=x) v++;
            }
            //cout<<"x";
            return v-N;
        }
    }
    //cout<<"y";
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        string t;
        cin>>t;
        cin>>Q[i].st.st>>Q[i].st.nd;
        if(t[0]=='a')  Q[i].nd=1;
        else if(t[0]=='r') Q[i].nd=-1;
        tab2[i]={{Q[i].st.st, Q[i].st.nd}, i};
    }
    tab2[q]={{-1, -1}, -1};
    sort(tab2, tab2+q);
    int wsk=0;
    /*for(int i=0; i<q; i++){
        tab2[i].st.nd=-tab2[i].st.nd;
    }*/
    for(int i=0; i<q; i++){
        tab4[wsk]=tab2[i].st;
        tab3[tab2[i].nd]=wsk;
        if(tab2[i].st!=tab2[i+1].st){
            wsk++;
        }
    }
    int wsk2;
    for(int i=q-1; i>=0; i--){
        if(tab2[i].st!=tab2[i+1].st){
            wsk--;
        }
        if(tab2[i].st.st!=tab2[i+1].st.st)  wsk2=wsk;
        tab5[tab2[i].nd]=wsk2;
    }
    memset(tab, -1, 2*N);
    for(int i=0; i<q; i++){
        //cout<<tab3[i]<<"a"<<Q[i].st.nd<<"\n\n";
        if(Q[i].nd==1){
            Set(tab3[i], Q[i].st.nd);
        }
        if(Q[i].nd==-1){
            Set(tab3[i], -1);
        }
        if(!Q[i].nd){
            int a=ans(tab5[i], Q[i].st.nd);
            if(a>=0)cout<<tab4[a].st<<" "<<tab4[a].nd<<"\n";
            else    cout<<"-1\n";
        }
    }
}