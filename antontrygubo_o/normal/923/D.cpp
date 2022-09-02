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

void f(string s, vector<int> &pref, vector<int> &pr)
{
    int n = s.length();
    pref.resize(n+1);
    pr.resize(n+1);
    pref[0] = 0;
    pr[0] = -1;
    for (int i = 0; i<n; i++)
    {
        pref[i+1] = pref[i] + (s[i]=='B'||s[i]=='C');
        if (s[i]!='A') pr[i+1] = -1;
        else 
        {
            if (pr[i]!=-1) pr[i+1] = pr[i];
            else pr[i+1] = i;
        }
    }
}


    string s, t;

    vector<int> pref_S;
    vector<int> prS;
    vector<int> pref_T;
    vector<int> prT;   

void solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    //cout<<endl<<endl;
    int bS = pref_S[b] - pref_S[a-1];
    int bT = pref_T[d] - pref_T[c-1];
    int aS, aT;
    if (s[b-1]!='A') aS = 0;
    else aS = min(b - prS[b], b-a+1);
    if (t[d-1]!='A') aT = 0;
    else aT = min(d - prT[d], d-c+1);
    /*cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    cout<<bS<<' '<<bT<<endl;
    cout<<aS<<' '<<aT<<endl;*/
    
    if (bS>bT) {cout<<0; return;}
    if (bT%2!=bS%2) {cout<<0; return;}
    if (aT>aS) {cout<<0; return;}
    if (aS==aT)
    {
        if (bS==0&&bT>0) {cout<<0; return;}
        cout<<1; return;
    }
    if (bS==bT)
    {
        cout<<((aS-aT)%3==0); return;
    }
    cout<<1; return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>s>>t;
    //cout<<s<<endl<<t<<endl;
    
    f(s, pref_S, prS);
    f(t, pref_T, prT); 
    
    /*print(pref_S);
    print(pref_T);
    print(prS);
    print(prT);*/
    

    
        //print(prS);    
    int q;
    cin>>q;
    for (int i = 0; i<q; i++) solve();
    

}