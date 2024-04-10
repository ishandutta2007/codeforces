#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
int tab[1000005];
stack<pair<long long, int> > S;
void insert(int x){
    int cnt=1;
    long long sum=x;
    while(!S.empty()){
        //cout<<S.top().st<<S.top().nd<<"\n";
        if(sum*S.top().nd<S.top().st*cnt){
           break;
        }
        //cout<<"b";
        sum+=S.top().st;
        cnt+=S.top().nd;
        S.pop();
    }
    //cout<<"a\n";
    S.push({sum, cnt});
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tab[i];
    }

    for(int i=n-1; i>=0; i--){
        insert(tab[i]);
    }
    while(!S.empty()){
        for(int i=0; i<S.top().nd; i++)
            cout<<fixed<<setprecision(9)<<((long double)S.top().st)/S.top().nd<<"\n";
        S.pop();
    }
}