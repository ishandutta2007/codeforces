#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int x = 1;
    int y = 1;
    vector<char> walk(n-1);
    string ans;
    for (int i = 0; i<n-1; i++)
    {
        cout<<'?'<<' '<<y+1<<' '<<x<<' '<<n<<' '<<n<<endl;
        cout.flush();
        cin>>ans;
        if (ans=="YES") {walk[i] = 'D'; y++;}
        else {walk[i] = 'R'; x++;}
    }
    
    vector<char> walkback (n-1);
    x = n;
    y = n;
    
    for (int i = 0; i<n-1; i++)
    {
        cout<<'?'<<' '<<1<<' '<<1<<' '<<y<<' '<<x-1<<endl;
        cout.flush();
        cin>>ans;
        if (ans=="YES") {walkback[i] = 'R'; x--;}
        else {walkback[i] = 'D'; y--;}
    }
    cout<<'!'<<' ';
    for (int i = 0; i<n-1; i++) cout<<walk[i];
    for (int i = n-2; i>=0; i--) cout<<walkback[i];

}