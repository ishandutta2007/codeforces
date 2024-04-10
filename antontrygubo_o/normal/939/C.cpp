#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() 
{
int n;
cin>>n;
long long a[n];
for (int i = 0; i<n-1; i++) cin>>a[i+1]; 
cin>>a[0];
int s, f;
cin>>s>>f;
int besttime = 1;
long long maxxpeople = 0;
long long current = 0;
for (int i = s; i<f; i++) current+=a[i];
maxxpeople = current;
//cout<<current<<endl;
for (int i = 1; i<=n-1; i++)
{
    current-=a[(f-i+n)%n];
    current+=a[(s-i+n)%n];
    //cout<<i+1<<' '<<current<<endl;
    if (current>maxxpeople) {maxxpeople = current; besttime = i+1;}
}

cout<<besttime;

}