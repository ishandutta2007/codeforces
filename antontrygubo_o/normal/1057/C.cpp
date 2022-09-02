#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int INF = 1e7;

int n, s, k;
int answer[50][2001];

int main()
{
    cin>>n>>s>>k;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    char color[n];
    for (int i = 0; i<n; i++) cin>>color[i];
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<=a[i]; j++) answer[i][j] = 0;
        for (int j = a[i]+1; j<=2000; j++) answer[i][j] = INF;
    }
    for (int i = 50; i>=1; i--)
    {
        for (int j = 0; j<n; j++) if (a[j]==i)
        {
            for (int k = 0; k<=2000; k++)
            {
                for (int l = 0; l<n; l++) if (a[l]>a[j]&&a[j]<k&&color[j]!=color[l]) answer[j][k] = min(answer[j][k], abs(j-l)+answer[l][k-a[j]]);
            }
        }
    }
    int res = answer[s-1][k];
    for (int i = 0; i<n; i++) res = min(res, abs(s-1-i)+answer[i][k]);
    if (res>=INF) cout<<-1;
    else cout<<res;
    
    
}