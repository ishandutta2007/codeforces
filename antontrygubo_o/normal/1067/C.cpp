#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
ll p = 1e9 + 7;
 
vector<vector<int>> G;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int k = (n-1)/3;
    int left = n-1-3*k;
    for (int i = 0; i<k+1; i++) cout<<2*i<<' '<<0<<endl;
    for (int i = 0; i<k; i++) cout<<2*i+1<<' '<<1<<endl;
    for (int i = 0; i<k; i++) cout<<2*i+1<<' '<<-1<<endl;
    for (int i = 0; i<left; i++) cout<< -1<<' '<<i<<endl;
    
}