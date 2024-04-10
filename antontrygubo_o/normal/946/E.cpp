#include<bits/stdc++.h>
using namespace std;


bool can(string s, int j)//   s   j ,  j+1
{
    int k = s.length();
    //, 
    int idx = j;
    if (j==k) return false;
    if (s[idx]=='0') return false;
    bool a[10] = {0};
    for (int i = 0; i<idx; i++) a[int(s[i])-48] = !a[int(s[i])-48];
    int t = 0;
    for (int i = 0; i<=9; i++) t+=a[i];
    if (t<k-idx) return true;
    if (t>k-idx) return false;
    for (int i = 0; i<10; i++) if ((int(s[idx])-48>i)&&(a[i]==1)) return true;
    return false;
}

void f(string s)
{
//cout<<"TEST"<<endl;

int k = s.length();
int idx = k-1;
bool t = false;
while ((!t)&&(idx>=1))
{
    if (s[idx]=='0') idx--;
    else
    {
        if (can(s, idx)) {t = true; break;}
        idx--;
    }

}

if (t==false)
{
    //cout<<"LOL"<<endl;
    if (s[0]=='1') for (int i = 0; i<k-2; i++) cout<<'9';
    else {cout<<char(int(s[0])-1); for (int i = 0; i<k-2; i++) cout<<'9'; cout<<char(int(s[0])-1);}
}

else
{
    //cout<<"idx"<<' '<<idx<<endl;
    for (int i = 0; i<idx; i++) cout<<s[i];
    //cout<<endl;
    bool a[10] = {0};
    for (int i = 0; i<idx; i++) a[int(s[i])-48] = !a[int(s[i])-48];
    int t = 0;
    for (int i = 0; i<=9; i++) t+=a[i];
    //cout<<'t'<<' '<<t<<endl;
    int left = k-idx;
    //cout<<"left"<<' '<<left<<endl;
    if (left>t)
    {
        cout<<char(int(s[idx])-1);
        a[int(s[idx])-49] = !a[int(s[idx])-49];
        t = 0;
        for (int i = 0; i<=9; i++) t+=a[i];
        for (int i = 0; i<left-t-1; i++) cout<<'9';
        for (int i = 9; i>=0; i--) if (a[i]) cout<<i;
    }
    
    else
    {
        int c = int(s[idx])-49;
        while (a[c]!=1) c--;
        a[c]=0; cout<<c;
        for (int i = 9; i>=0; i--) if (a[i]==1) cout<<i;        
    }
    
    
}

cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    string s;
    for (int i = 0; i<t; i++) {cin>>s; f(s);}
}