#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int h[200005];
int maxf[200005];
int minf[200005];

int main()
{
    int z;
    cin>>z;
    while(z--){

        int n, k;
        cin>>n>>k;

        for(int i=0;i<n;i++){
            cin>>h[i];
        }

        maxf[0] = h[0];
        minf[0] = h[0];

        int i;

        for(i=1;i<n;i++){
            if(maxf[i-1]+k-1 < h[i] || minf[i-1]-(k-1) > h[i]+(k-1)){
                cout<<"NO"<<endl;
                break;
            }
            maxf[i] = min(maxf[i-1]+k-1, h[i]+k-1);
            minf[i] = max(minf[i-1]-(k-1), h[i]);
        }
        if(i!=n)
            continue;
        if(h[n-1]>=minf[n-1] && h[n-1]<=maxf[n-1])
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }
}