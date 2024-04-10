#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<ll> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if (n%4==2||n%4==3) {cout<<"NO"; return 0;}
    else cout<<"YES"<<endl;
    if (n%4==0)
    {
        for (int j = 0; j<n; j+=4) cout<<j+1<<' '<<j+2<<endl<<j+3<<' '<<j+4<<endl<<j+2<<' '<<j+3<<endl<<j+1<<' '<<j+4<<endl<<j+1<<' '<<j+3<<endl<<j+2<<' '<<j+4<<endl;
        for (int j = 0; j<n; j+=4)
        for (int k = j+4; k<n; k+=4)
        {
            cout<<j+1<<' '<<k+1<<endl<<j+2<<' '<<k+2<<endl<<j+3<<' '<<k+3<<endl<<j+4<<' '<<k+4<<endl;
            cout<<j+1<<' '<<k+2<<endl<<j+2<<' '<<k+1<<endl<<j+3<<' '<<k+4<<endl<<j+4<<' '<<k+3<<endl;
            cout<<j+1<<' '<<k+3<<endl<<j+2<<' '<<k+4<<endl<<j+3<<' '<<k+1<<endl<<j+4<<' '<<k+2<<endl;
            cout<<j+1<<' '<<k+4<<endl<<j+2<<' '<<k+3<<endl<<j+3<<' '<<k+2<<endl<<j+4<<' '<<k+1<<endl;
        }
    }
    if (n%4==1)
    {
        if (n==1) return 0;
        n -=5;
        for (int j = 0; j<n; j+=4) cout<<j+1<<' '<<j+2<<endl<<j+3<<' '<<j+4<<endl<<j+2<<' '<<j+3<<endl<<j+1<<' '<<j+4<<endl<<j+1<<' '<<j+3<<endl<<j+2<<' '<<j+4<<endl;
        for (int j = 0; j<n; j+=4)
        for (int k = j+4; k<n; k+=4)
        {
            cout<<j+1<<' '<<k+1<<endl<<j+2<<' '<<k+2<<endl<<j+3<<' '<<k+3<<endl<<j+4<<' '<<k+4<<endl;
            cout<<j+1<<' '<<k+2<<endl<<j+2<<' '<<k+1<<endl<<j+3<<' '<<k+4<<endl<<j+4<<' '<<k+3<<endl;
            cout<<j+1<<' '<<k+3<<endl<<j+2<<' '<<k+4<<endl<<j+3<<' '<<k+1<<endl<<j+4<<' '<<k+2<<endl;
            cout<<j+1<<' '<<k+4<<endl<<j+2<<' '<<k+3<<endl<<j+3<<' '<<k+2<<endl<<j+4<<' '<<k+1<<endl;
        }
        cout<<n+3<<' '<<n+4<<endl<<n+3<<' '<<n+5<<endl<<n+4<<' '<<n+5<<endl<<n+2<<' '<<n+4<<endl<<n+1<<' '<<n+2<<endl<<n+1<<' '<<n+4<<endl;
        cout<<n+1<<' '<<n+5<<endl<<n+2<<' '<<n+3<<endl<<n+1<<' '<<n+3<<endl<<n+2<<' '<<n+5<<endl;
        for (int j = 0; j<n; j+=4)
        {
            cout<<j+1<<' '<<n+1<<endl<<j+2<<' '<<n+3<<endl<<j+2<<' '<<n+2<<endl<<j+1<<' '<<n+2<<endl<<j+2<<' '<<n+1<<endl<<j+1<<' '<<n+3<<endl;
            cout<<j+3<<' '<<n+3<<endl<<j+4<<' '<<n+1<<endl<<j+3<<' '<<n+2<<endl<<j+4<<' '<<n+2<<endl<<j+4<<' '<<n+3<<endl<<j+3<<' '<<n+1<<endl;
            cout<<j+1<<' '<<n+4<<endl<<j+2<<' '<<n+5<<endl<<j+1<<' '<<n+5<<endl<<j+2<<' '<<n+4<<endl;
            cout<<j+3<<' '<<n+4<<endl<<j+4<<' '<<n+5<<endl<<j+3<<' '<<n+5<<endl<<j+4<<' '<<n+4<<endl;
        }
    }
    
}