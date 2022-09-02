#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) if(a[i]!=-1) a[i]--;
    vector<vector<ll> > b(200, vector<ll> (3)); //0 if prev was < then current, 1 if equal, 2 if > then current
    vector<vector<ll> > c(200, vector<ll> (3));   
    if (a[0]!=-1) b[a[0]][0] = 1;
    else
    {
        for (int i = 0; i<200; i++)
        b[i][0] = 1;
    }
    for (int i = 1; i<n; i++)
    {
        vector<int> temp2(200);
        temp2[199] = (b[199][1] + b[199][2])%p;
        for (int j = 198; j>=0; j--) temp2[j] = (temp2[j+1] + b[j][2] + b[j][1])%p;
        vector<int> temp0(200);
        temp0[0] = (b[0][0]+b[0][1] + b[0][2])%p;
        for (int j = 1; j<200; j++) temp0[j] = (temp0[j-1] + b[j][0] + b[j][1] + b[j][2])%p;
        
        if (a[i]!=-1)
        {
            if (a[i]!=0) c[a[i]][0] = temp0[a[i]-1];
            c[a[i]][1] = (b[a[i]][0] + b[a[i]][1] + b[a[i]][2])%p;
            if (a[i]!=199) c[a[i]][2] = (temp2[a[i]+1])%p;
            for (int j = 0; j<200; j++) if (j!=a[i]) {c[j][0] = 0; c[j][1] = 0; c[j][2] = 0;}
        }
        else for(int j = 0; j<=199; j++)
        {
            a[i] = j;
            if (a[i]!=0) c[a[i]][0] = temp0[a[i]-1]; else c[a[i]][0] = 0;
            c[a[i]][1] = (b[a[i]][0] + b[a[i]][1] + b[a[i]][2])%p;
            if (a[i]!=199) c[a[i]][2] = (temp2[a[i]+1])%p; else c[a[i]][2] = 0;
        }

        b = c;
    }

     
    ll result = 0;
    for (int i = 0; i<200; i++)
    {
        result = (result+b[i][1]+b[i][2])%p;
    }
    cout<<result<<endl;
    
    
}