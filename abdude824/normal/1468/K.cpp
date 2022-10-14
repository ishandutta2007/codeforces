#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        int x=0;
        int y=0;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
               x--;
               v.pb({x,y});
            }
            else if(s[i]=='U')
            {
               y++;
               v.pb({x,y});
            }
             else if(s[i]=='R')
            {
               x++;
               v.pb({x,y});
            }
             else if(s[i]=='D')
            {
               y--;
               v.pb({x,y});
            }
        }
        int obstacle1,obstacle2;
        int kttr=0;
        for(int i=0;i<v.size();i++)
        {
            obstacle1=v[i].first;
            obstacle2=v[i].second;
            int cost=0;
            int x=0,y=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='L')
            {
               x--;
               if(x==obstacle1&&y==obstacle2)
               {
                 x++;
               }
               else 
               {
                   cost+=1;
               }
               //v.pb({x,y});
            }
            else if(s[i]=='U')
            {
               y++;
                if(x==obstacle1&&y==obstacle2)
               {
                  y--;
               }
               else 
               {
                   cost+=1e5;
               }
               //v.pb({x,y});
            }
             else if(s[i]=='R')
            {
               x++;
                if(x==obstacle1&&y==obstacle2)
               {
x--;
               }
               else 
               {
                   cost+=-1;
               }
               //v.pb({x,y});
            }
             else if(s[i]=='D')
            {
               y--;
                if(x==obstacle1&&y==obstacle2)
               {
y++;
               }
               else 
               {
                   cost+=-1e5;
               }
               //v.pb({x,y});
            }
            }
            //cout<<cost<<" "<<obstacle1<<" "<<obstacle2<<"\n";
            if(cost==0)
            {
                cout<<obstacle1<<" "<<obstacle2<<"\n";
                kttr=1;
                break;
            }
        }
         if(kttr==0)
         {
             cout<<0<<" "<<0<<"\n";
         }
    }
}