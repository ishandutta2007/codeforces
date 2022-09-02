#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, k;
cin>>n>>k;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
map<int, int> low;
for (int i = 0; i<=255; i++) low[i] = -1;

for (int i = 0; i<n; i++)
{
    if (low[a[i]]==-1) 
    {
        int kek = a[i];
        while (low[kek]==-1&&kek>a[i]-k&&kek>=0) kek--;
        if (kek>=0&&kek>a[i]-k)
        {
            if (low[kek]>a[i]-k) kek=low[kek]-1;
        }
        kek++;
        for (int j = kek; j<=a[i]; j++) {low[j] = kek;}
    }
}

for (int i = 0; i<n; i++) cout<<low[a[i]]<<' ';

}