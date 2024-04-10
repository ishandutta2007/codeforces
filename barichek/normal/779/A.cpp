#include <bits/stdc++.h>

using namespace std;

bool reb[100][100];
int n;
int cnt_a[10];
int cnt_b[10];

main()
{int n;
int fatb=0;
int fbta=0;
cin>>n;
int a[1000];
int b[1000];
for (int i=1; i<=n; i++)
    cin>>a[i];
for (int i=1; i<=n; i++)
    cin>>b[i];
for (int i=1; i<=n; i++)
{
    cnt_a[a[i]]++;
    cnt_b[b[i]]++;
}
for(int i=1; i<=5; i++)
{
    if ((cnt_a[i] + cnt_b[i])%2==1){
        cout<<"-1";
    return 0;
    }
    else {
        if(cnt_a[i]>cnt_b[i])
            fatb+=cnt_a[i] - cnt_b[i];
            else fbta+=cnt_b[i] - cnt_a[i];
    }
}
if(fbta!=fatb){
    cout<<"-1";
    return 0;
}
else cout<<fbta/2;
}