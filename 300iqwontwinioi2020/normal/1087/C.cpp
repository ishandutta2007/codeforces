#include <bits/stdc++.h>

using namespace std;

pair < int, int > P[3];

int x[5], y[5];
int mas[1005][1005];
vector < int > v1, v2;

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 3; i++)
        cin>>P[i].first>>P[i].second;
    sort (P, P + 3);
    for (int i = 0; i < 3; i++){
        x[i + 1] = P[i].first;
        y[i + 1] = P[i].second;
    }
    for (int i = x[1]; i <= x[2]; i++)
        for (int j = y[1]; j <= y[1]; j++)
            mas[i][j] = 1;
    for (int i = x[2]; i <= x[2]; i++)
        for (int j = min (y[1], y[2]); j <= max (y[1], y[2]); j++)
            mas[i][j] = 1;
    for (int i = x[2]; i <= x[3]; i++)
        for (int j = y[3]; j <= y[3]; j++)
            mas[i][j] = 1;
    for (int i = x[2]; i <= x[2]; i++)
        for (int j = min (y[2], y[3]); j <= max (y[2], y[3]); j++)
            mas[i][j] = 1;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
    if (mas[i][j]){
        v1.push_back (i);
        v2.push_back (j);
    }
    cout<<(int)v1.size()<<endl;
    for (int i = 0; i < (int)v1.size(); i++)
        cout<<v1[i]<<" "<<v2[i]<<endl;
    return 0;
}