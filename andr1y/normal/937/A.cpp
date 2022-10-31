#include <bits/stdc++.h>
#define SPEED cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
using namespace std;
void B(){
    SPEED;
    int n, k, A, B, x, s=0;
    cin >> n >> k >> A >> B;
    x=n;
    vector<int> kD;
    for(int i=k;i<=n;i+=k)kD.push_back(i);
    s+=(x-kD[kD.size()-1])*A;
    x=kD[kD.size()-1];
    s+=(kD.size()-1)*B;
    cout << s;
}
void A937(){
    SPEED;
    int n, c=0;
    cin >> n;
    map<int, int> a;
    for(int i=0;i<n;i++){int t;cin>>t;if(t!=0)a[t]++;}
    for(map<int, int>::iterator i=a.begin();i!=a.end();i++){if(i->second!=0)c++;}
    cout << c;
}
int main()
{
    A937();
}