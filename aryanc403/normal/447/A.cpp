#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int mod,n,i,j;
    set<int> s;
    cin>>mod>>n;
    for(i=1;i<=n;++i)
    {
        cin>>j;
        j%=mod;
        if(s.find(j)!=s.end())
        {
            cout<<i<<endl;
            return 0;
        }
        s.insert(j);
    }
    cout<<-1<<endl;
    return 0;
}