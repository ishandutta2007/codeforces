#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const ll p = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

ll l = 0;
ll r = 1e9;
void bin_search()
{
    bool t;
    /*cout<<"> "<<0<<endl;
    cin>>t;
    if (!t) {r = 0; return;}*/
    while (r-l>1)
    {
        ll mid = (l+r)/2;
        cout<<"> "<<mid<<endl;
        cin>>t;
        if (t) l = mid;
        else r = mid;
    }
}

int n;

mt19937 rnd(228);

int ask(int i)
{
    cout<<"? "<<i<<endl;
    int res;
    //res = 1e9 - (n-i)*1000;
    cin>>res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    cin>>n;
    vector<int> el;
    bin_search();
    
    
    if (n>30)
    {
        for (int i = 0; i<30; i++) el.push_back(ask(rnd()%n + 1));
        int k = el.size();
        vector<int> dif;
        for (int i = 0; i<k; i++)
        for (int j = i+1; j<k; j++) if (el[i]!=el[j]) dif.push_back(abs(el[j]-el[i]));
    
        int gcd = dif[0];
    
        for (int i = 0; i<dif.size(); i++) gcd = __gcd(gcd, dif[i]);
        cout<<"! "<<r - (n-1)*gcd<<' '<<gcd<<endl;
    }
    else
    {
        int minn = r;
        int temp;
        for (int i = 0; i<n; i++)
        {
            temp = ask(i+1);
            minn = min(minn, temp);
        }
        cout<<"! "<<minn<<' '<<(r-minn)/(n-1)<<endl;
    }
}