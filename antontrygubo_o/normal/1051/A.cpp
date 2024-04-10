#include <bits/stdc++.h>
using namespace std;

#define ll long long

string f(string s)
{
    int small, number, big;
    small = 0;
    number = 0;
    big = 0;
    int k = s.length();
    for (int i = 0; i<k; i++)
    {
        if (s[i]<='9'&&s[i]>='0') number++;
        if ('a'<=s[i]&&s[i]<='z') small++;
        if ('A'<=s[i]&&s[i]<='Z') big++;
    }
    if (number>0&&small>0&&big>0) return s;
    if (small==0&&big==0) {s[0] = 'a'; s[1] = 'A'; return s;}
    if (small==0&&number==0) {s[0] = 'a'; s[1] = '1'; return s;} 
    if (number==0&&big==0) {s[0] = '1'; s[1] = 'A'; return s;}
    if (small==0)
    {
        if (big>1)
        {
            int i = 0;
            while (s[i]<'A'||s[i]>'Z') i++; 
            s[i] = 'a';
            return s;
        }
        else
        {
            int i = 0;
            while (s[i]<'0'||s[i]>'9') i++; 
            s[i] = 'a';
            return s;
        }
    }
    
    if (big==0)
    {
        if (small>1)
        {
            int i = 0;
            while (s[i]<'a'||s[i]>'z') i++; 
            s[i] = 'A';
            return s;
        }
        else
        {
            int i = 0;
            while (s[i]<'0'||s[i]>'9') i++; 
            s[i] = 'A';
            return s;
        }
    }
    
    if (number==0)
    {
        if (big>1)
        {
            int i = 0;
            while (s[i]<'A'||s[i]>'Z') i++; 
            s[i] = '1';
            return s;
        }
        else
        {
            int i = 0;
            while (s[i]<'a'||s[i]>'z') i++; 
            s[i] = '1';
            return s;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
        
    int t;
    string s;
    cin>>t;
    for (int i = 0; i<t; i++)
    {
        cin>>s; cout<<f(s)<<endl;
    }
    
    
}