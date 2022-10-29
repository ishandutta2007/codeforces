#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

string s;
int add1[N], subt[N];
int sz, plus1=1, minus1=0;

int32_t main()
{
    IOS;
    getline(cin, s);
    sz=s.size();
    string cur;
    for(int i=sz-1;i>=0;i--)
    {
        if(!isdigit(s[i]))
            break;
        cur+=s[i];
    }
    for(auto it:s)
    {
        if(it=='+')
            plus1++;
        else if(it=='-')
            minus1++;
    }
    reverse(cur.begin(), cur.end());
    int n=0;
    for(auto it:cur)
        n=n*10 + (it-'0');
    for(int i=1;i<=100;i++)
    {
        add1[i]=subt[i]=1;
    }
    int diff=plus1-minus1-n;
    if(diff>0)
    {
        for(int i=1;i<=minus1;i++)
        {
            int cur=min(n-1, diff);
            subt[i]+=cur;
            diff-=cur;
        }
        if(diff!=0)
        {
            cout<<"Impossible";
            return 0;
        }
    }
    else 
    {
        diff=abs(diff);
        for(int i=1;i<=plus1;i++)
        {
            int cur=min(n-1, diff);
            add1[i]+=cur;
            diff-=cur;
        }
        if(diff!=0)
        {
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    s='+' + s;
    int p=1, q=1;
    for(int i=0;i<s.size();i++)
    {
        if(i!=0 && s[i]!='?')
            cout<<s[i];
        if(s[i]=='?')
        {
            if((i==1) || s[i-2]=='+')
            {
                cout<<add1[p++];
            }
            else
            {
                cout<<subt[q++];
            }
        }
    }
    return 0;
}