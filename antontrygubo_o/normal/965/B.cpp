#include<bits/stdc++.h>
using namespace std;


int main()
{
int n, k;
cin>>n>>k;
bool game[n+1][n+1];
for (int i = 0; i<n; i++)
{
    string s;
    cin>>s;
    for (int j = 0; j<n; j++) if (s[j]=='.')  game[i][j] = true; else game[i][j] = false;
    game[i][n] = false;
}



for (int i = 0; i<=n; i++) game[n][i] = false;

int counter[n][n] = {0};

for (int i = 0; i<n; i++)
{
    for(int j = 0; j<n; j++) counter[i][j]=0;
}

for (int i = 0; i<=n; i++)
{
    int currentlength = 0;
    for (int j = 0; j<=n; j++)
    {
        if (game[i][j]) currentlength++;
        else
        {
            if (currentlength>=k)
            {
                for (int s = j-1; s>=j-currentlength; s--) 
                {
                    int kek = j-1-s;
                    int l = max(0, kek-k+1);
                    int r = min(currentlength-k, kek);
                    counter[i][s]+=(r-l+1);
                }
            }
            currentlength = 0;
        }
    }
}


for (int j = 0; j<=n; j++)
{
    int currentlength = 0;
    for (int i = 0; i<=n; i++)
    {
        if (game[i][j]) currentlength++;
        else
        {
            if (currentlength>=k)
            {
                for (int s = i-1; s>=i-currentlength; s--) 
                {
                    int kek = i-1-s;
                    int l = max(0, kek-k+1);
                    int r = min(currentlength-k, kek);
                    counter[s][j]+=(r-l+1);
                }
            }
            currentlength = 0;
        }
    }
}

int a, b;
int maxx = -1;
for (int i = 0; i<n; i++)
for (int j = 0; j<n; j++) 
if (counter[i][j]>maxx) {maxx = counter[i][j]; a = i; b = j;}

cout<<a+1<<' '<<b+1;


}