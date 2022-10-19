#include<bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<int, pair<int, int > > pii;
const int N=1e5+5;
pii E[N];
int ans[N], d[N];

int main(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        cin>>E[i].nd.st>>E[i].nd.nd;
        E[i].st=i;
        d[E[i].nd.st]++;
        d[E[i].nd.nd]++;
    }
    sort(E+1, E+n, [](pii a, pii b){return (min(d[a.nd.st], d[a.nd.nd]) < min(d[b.nd.st], d[b.nd.nd]));});
    for(int i=1; i<n; i++){
        //cout<<E[i].st<<"\n";
        ans[E[i].st]=i-1;
    }
    for(int i=1; i<n; i++){
        cout<<ans[i]<<"\n";
    }
}