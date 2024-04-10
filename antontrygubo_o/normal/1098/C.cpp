#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n, s;

bool check(ll t)
{
    ll res = 0;
    ll cur = 1;
    int n1 = n;
    for (int i = 1; n1>0; i++)
    {
        if (n1>=cur) {res+=cur*i; n1-=cur; cur*=t;}
        else {res+=n1*i; cur*=t; n1 = 0;}
    }
    return (res<=s);
}


void draw(ll t)
{
    vector<int> a(n+1);
    ll res = 0;
    ll cur = 1;
    int n1 = n;
    for (int i = 1; n1>0; i++)
    {
        if (n1>=cur) {a[i] = cur; n1-=cur; res+=cur*i; cur*=t;}
        else {a[i] = n1; res+=n1*i; cur*=t; n1 = 0;}
        //cout<<i<<' '<<n1<<endl;
    }    
    
    int last = 1;
    while (a[last]!=0&&last<=n) last++;
    last--;
    
    s-=res;

    //for (int i = 0; i<=n; i++) cout<<a[i]<<' ';
    
    int ptr = last;
    while (s)
    {
        while (a[ptr]==1) ptr--;
        if (last-ptr>=s) {a[ptr]--; a[ptr+s]++; s = 0;}
        else {a[ptr]--; last++; a[last]++; s-= (last-ptr);}
    }

    /*for (int i = 0; i<=n; i++) cout<<a[i]<<' ';
    cout<<endl;*/
    
    int idx = 1;
    for (int i = 2; i<=n; i++)
    {
        for (int j = 0; j<a[i]; j++) cout<<idx+j/t<<' ';
        idx+=a[i-1];
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
 
      
 
    cin>>n>>s;
    //cout<<n<<' '<<s<<endl;
    if (s<=2*n-2||2*s>n*(n+1)) {cout<<"No"; return 0;}
    cout<<"Yes"<<endl;
    if (s==2*n-1)
    {
        for (int i = 0; i<n-1; i++) cout<<1<<' ';
        return 0;
    }
    
    
    
    int l = 1;
    int r = n;
    if (check(1)) r = 1;
    while (r-l>1)
    {
        int mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    //cout<<r<<endl;
    
    draw(r);
}