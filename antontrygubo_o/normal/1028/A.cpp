#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin>>n>>m;
    char a[n][m];
    for (int i = 0; i<n; i++) 
    {
        for (int j = 0; j<m; j++) cin>>a[i][j];
    }
    int row;
    int col;
    for (int i = 0; i<n; i++)
    {
        int start, finish;
        int idx = 0;
        while (idx<m&&a[i][idx]=='W') idx++;
        if (idx!=m)
        {
            start = idx;
            while (idx<m&&a[i][idx]=='B') idx++;
            finish = idx-1;
            col = (start+finish)/2;
        }
    }
    
        for (int i = 0; i<m; i++)
    {
        int start, finish;
        int idx = 0;
        while (idx<n&&a[idx][i]=='W') idx++;
        if (idx!=n)
        {
            start = idx;
            while (idx<n&&a[idx][i]=='B') idx++;
            finish = idx-1;
            row = (start+finish)/2;
        }
    }

    
    cout<<row+1<<' '<<col+1;
    
}