#include<bits/stdc++.h>
const int MAXN=1000500;
const int inf=1000000000;
using namespace std;
#define endl '\n'

string s, t;
long long ss[30];
long long an;
long long ts[30];
long long needan;
int let[30];
bool can(int times)
{
    needan=0ll;
    for(int i=0; i<30; i++)
    {
        if(ss[i]<times*1ll*ts[i]) needan+=times*1ll*ts[i]-ss[i];
    }
    
    return ((long long)needan)<=((long long)an);
}

void mainp()
{
    cin>>s>>t;
    for(int i=0; i<s.size(); i++) {if(s[i]=='?') an++; else ss[s[i]-'a']++;}
    for(int i=0; i<t.size(); i++) ts[t[i]-'a']++;
    
    int l=0, r=MAXN, ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(can(mid)) 
        {
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    
    for(int i=0; i<30; i++)
    {
        if(ss[i]<ans*ts[i]) let[i]+=ans*ts[i]-ss[i];
    }
    
    int noww=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='?')
        {
            while(let[noww]<=0&&noww<30) noww++;
            
            if(noww>=29) s[i]='a';
            else
            {
                s[i]=noww+'a';
                let[noww]--;
            }
        }
    }
    
    cout<<s<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    mainp();
    return 0;
}