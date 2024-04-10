#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int cnt=0,n,m,i,j,rx=0,ry=0,lx=1e9,ly=1e9;
    string s;
    cin>>n>>m;
    for(i=0;i<n;++i)
    {
        cin>>s;
        for(j=0;j<m;++j)
        {
            if(s[j]=='W')
                continue;
            cnt++;
            lx=min(lx,i);rx=max(rx,i);
            ly=min(ly,j);ry=max(ry,j);
        }
    }

    if(cnt==0)
    {
        cout<<1<<endl;
        return 0;
    }

    i=1+max(rx-lx,ry-ly);
    cerr<<i<<endl;
    if(i>n||i>m)
    {
        cout<<-1<<endl;
        return 0;
    }

    cout<<i*i-cnt<<endl;
    return 0;
}