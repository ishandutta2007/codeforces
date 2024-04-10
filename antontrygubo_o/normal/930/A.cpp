#include <bits/stdc++.h>
using namespace std;


int main()
{
int n;
cin>>n;
int pre[n];
int dis[n] = {0};
int temp;
for (int i = 1; i<n; i++)
{
    cin>>temp; dis[i] = dis[temp-1]+1;
}

int coun[n] = {0};
for (int i = 0; i<n; i++) coun[dis[i]]++;
int summ = 0;
for (int i = 0; i<n; i++) summ += coun[i]%2;
cout<<summ;

}