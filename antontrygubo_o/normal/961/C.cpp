#include <bits/stdc++.h>

using namespace std;


int f(int n, int a[][100])
{
    int counter = 0;
    for (int i=0; i<n; i++)
    for (int j = 0; j<n; j++) if((i+j+a[i][j])%2!=0) counter++;
    return counter;

}

int main() 
{
int n;
cin>>n;
int a[4][100][100] = {0};
string l;
for (int s = 0; s<4; s++)
{
    for (int i = 0; i<n; i++)
    {
        cin>>l;
        if (l.length()==0) cin>>l;
        for (int j = 0; j<n; j++) if (l[j]=='1') a[s][i][j]=1;
    }
}





int kek[4];
for (int i = 0; i<4; i++) kek[i] = f(n, a[i]);
sort(kek, kek+4);

cout<<kek[0]+kek[1]-kek[2]-kek[3]+2*n*n;

}