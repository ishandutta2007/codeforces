#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
        
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
int counter[101];
for (int i = 0; i<=100; i++) counter[i] = 0;
for (int i = 0; i<n; i++) counter[a[i]]++;
int count1 = 0;
int count3 = 0;
for (int i = 0; i<101; i++)
{
    if (counter[i]==1) count1++;
    if (counter[i]>=3) count3++;
}

if (count3==0&&count1%2==1) {cout<<"NO"; return 0;}
cout<<"YES"<<endl;
if (count1%2==0)
{
    bool cur= true;
    for (int i = 0; i<n; i++)
    {
        if (counter[a[i]]!=1) cout<<'A';
        else
        {
            if (cur) cout<<'A';
            else cout<<'B';
            cur = !cur;
        }
    }
    return 0;
}

int my = 0;
while (counter[my]<3) my++;
    
    bool checkmy = false;
    bool cur= true;
    for (int i = 0; i<n; i++)
    {
        if (a[i]==my)
        {
            if (!checkmy) {cout<<'B'; checkmy = true;}
            else cout<<'A';
        }
        else if (counter[a[i]]!=1) cout<<'A';
        else
        {
            if (cur) cout<<'A';
            else cout<<'B';
            cur = !cur;
        }
    }
    

    
}