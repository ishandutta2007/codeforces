#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
pair<int, int> tab[200005];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tab[i].st;
    }
    for(int i=0; i<n; i++){
        cin>>tab[i].nd;
    }
    sort(tab, tab+n);
    priority_queue<int> Q;
    long long ans=0, sum=0;
    int k=-1;
    tab[n].st=2e9;
    for(int i=0; i<n; i++){
        if(tab[i].st==tab[i+1].st or !Q.empty()){
            k=tab[i].st;
            Q.push(tab[i].nd);
            sum+=tab[i].nd;
        }
        while(!Q.empty() and k<tab[i+1].st){
            //cout<<i;
            sum-=Q.top();
            Q.pop();
            ans+=sum;
            k++;
        }
    }
    cout<<ans;
}