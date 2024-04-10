#include<bits/stdc++.h>
using namespace std;

int main()
{
//freopen ("codeforces.txt", "r", stdin);
int n;
cin>>n;
int a[100000] = {0};
int b;
for (int i = 0; i<n; i++)
{
    cin>>b;
    a[b-1]++;
}
bool indicator = true;
for (int i = 0; i<100000; i++) if (a[i]%2==1) indicator = false;
if (indicator==false) cout<<"Conan";
else cout<<"Agasa";


}